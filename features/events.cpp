/*  events.cpp
 *
 *
 */
#include "common.h"
#include "events.h"

void bullet_impact(game_event_t* event)
{
    // bullet_impact
    if(strcmp(event->get_name(), __FUNCTION__))
        return;
    
}

void player_hurt(game_event_t* event)
{
    // player_hurt
    if(strcmp(event->get_name(), __FUNCTION__))
        return;
    
}
