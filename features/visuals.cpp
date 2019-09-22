/*  visuals.cpp
 *
 *
 */
#include "common.h"
#include "visuals.h"
#include "renderer.h"


visuals_t* g_visuals = new visuals_t;

/*
 *
 *
 */
static void draw_esp_box(player_box_t box, color_t color)
{
    g_render->draw_box(box.x - 1, box.y - 1, box.w + 2, box.h + 2, color_t::black);
    g_render->draw_box(box.x + 1, box.y + 1, box.w - 2, box.h - 2, color_t::black);
    g_render->draw_box(box.x, box.y, box.w, box.h, color);
}

/*
 *  draw_health_bar
 *
 */
static void draw_heath_bar(player_box_t box, int value, color_t color)
{
    value = util_clamp(value, 0, 100);
    
    int fill = box.h - (box.h * value) / 100;
    
    g_render->draw_box_filled(box.x - 5, box.y - 1, 3, box.h + 2, color_t(0, 0, 0, 120));
    g_render->draw_box_filled(box.x - 5, box.y + fill - 1, 3, box.h - fill + 2, color);
    g_render->draw_box(box.x - 5, box.y - 1, 3, box.h + 2, color_t(0, 0, 0, 200));
}

/*
 *
 *
 */
static void draw_skeleton(player_t* player)
{
    matrix3x4_t matrix[128];
    studio_hdr_t* model = g_model_info->get_studio_model(player->get_model());
    
    if(!model)
        return;
    
    if(!player->setup_bones(matrix, 128, 256))
        return;
    
    for(int i = 0; i < model->m_num_bones; i++)
    {
        studio_bone_t* bone = model->get_bone(i);
        
        if (!bone || !(bone->m_flags & 256) || bone->m_parent == -1)
            continue;
        
        matrix3x4_t hitbox1 = matrix[i];
        matrix3x4_t hitbox2 = matrix[bone->m_parent];
        
        vec3_t bone1(hitbox1[0][3], hitbox1[1][3], hitbox1[2][3]), bone1_screen;
        vec3_t bone2(hitbox2[0][3], hitbox2[1][3], hitbox2[2][3]), bone2_screen;
        
        color_t col = color_t::white; //
        
        if(world_to_screen(bone1, bone1_screen) && world_to_screen(bone2, bone2_screen))
            g_render->draw_line(bone1_screen.x, bone1_screen.y, bone2_screen.x, bone2_screen.y, col);
    }
}

/*
 *  draw_player_esp
 *  Draw visuals on players
 */
void visuals_t::draw_player_esp()
{
    if(!global::local)
        return;
    
    for(int i = 1; i < g_globals->m_max_clients; i++)
    {
        player_t* player = (player_t*)g_ent_list->get_entity(i);

        if(!player)
            continue;

        if(!player->is_player())
            continue;
        
        if(!player->is_alive())
            continue;
        
        int team = player->get_team();
        
        // if not an actual player then
        if(team != TEAM_TERRORIST && team != TEAM_COUNTER_TERRORIST)
            continue;
        
        int my_team = global::local->get_team();
        
        if(set.visuals.team_flags == 0 && my_team == team)
            continue;
        else if(set.visuals.team_flags == 1 && my_team != team)
            continue;
        // else if == 2 draw all
        
        // only how visible players?
        if(set.visuals.visible && !util_is_player_visible(player))
            continue;
        
        player_box_t box = get_player_box(player);
        
        if(!box.valid)
            continue;
        
        color_t box_col  = set.colors.players.box.to_color();
        
        player_info_t info;
        g_engine->get_player_info(i, &info);
        
        // draw bounding box
        if(set.visuals.player.box)
            draw_esp_box(box, box_col);
        
        // draw name on top
        if(set.visuals.player.name)
            g_render->draw_string(box.x + (box.w / 2), box.y - 15, renderer_t::verdana12, info.name, color_t::white, true);
        
        if(set.visuals.player.health)
            draw_heath_bar(box, player->get_health(), color_t::green);
        
        if(set.visuals.player.skeleton)
            draw_skeleton(player);
    }
}

/*
 *  draw_other_esp
 *  Draw visuals for other entities
 */
void visuals_t::draw_other_esp()
{
    for(int i = 64; i < g_ent_list->get_highest_index(); i++)
    {
        entity_t* entity = g_ent_list->get_entity(i);

        if(!entity)
            continue;

    }
}
