/*  frame_stage_notify.cpp
 *
 *
 */
#include "common.h"

void frame_stage_notify_hook(void* thisptr, frame_stage_t frame_stage)
{
    print_hook();
    
    bool in_game = g_engine->is_in_game();
    
    if(frame_stage == FRAME_START)
    {
        
    }
    
    if(frame_stage == FRAME_NET_UPDATE_START)
    {
        
    }
    
    if(frame_stage == FRAME_NET_UPDATE_POSTDATAUPDATE_START)
    {
        
    }
    
    if(frame_stage == FRAME_NET_UPDATE_POSTDATAUPDATE_END)
    {
       
    }
    
    if(frame_stage == FRAME_NET_UPDATE_END)
    {
        
    }
    
    if(frame_stage == FRAME_RENDER_START)
    {
     
    }
    
    if(frame_stage == FRAME_RENDER_END)
    {
        
    }
    
    client_vmt->get_original_method<frame_stage_notify_fn>(INDEX_FRAME_STAGE_NOTIFY)(thisptr, frame_stage);
}
