/*  paint_traverse.cpp
 *
 *
 */
#include "common.h"
#include "renderer.h"
#include "visuals.h"

void paint_traverse_hook(void* thisptr, VPANEL panel, bool repaint, bool allow_force)
{
    print_hook();
    
    panel_vmt->get_original_method<paint_traverse_fn>(INDEX_PAINT_TRAVERSE)(thisptr, panel, repaint, allow_force);
    
    static VPANEL focus_panel = 0;
    
    if(!focus_panel)
    {
        if(strstr(g_panel->get_name(panel), "FocusOverlayPanel"))
        {
            focus_panel = panel;
            
            renderer_t::verdana12 = g_render->create_font("Verdana Bold", 12, FONTFLAG_DROPSHADOW);
        }
    }
    
    if(panel == focus_panel)
    {
        if(g_engine->is_in_game())
        {
            // features
            g_visuals->draw_player_esp();
            g_visuals->draw_other_esp();
        }
        else
        {
            g_render->draw_string(10, 10, renderer_t::verdana12, "pwned", color_t(230, 40, 240, 255));
        }
    }
}
