/*
 *  settings.h
 */
#pragma once

#include "imgui.h"

// multi combo settings
typedef std::vector<bool> multi;

struct settings_t
{
    // current config
    int config  = 0;
    
    struct
    {
        bool    open    = false;
        int     key     = -1;       // todo
    }menu;
    
    // screen size
    struct
    {
        int w, h;
    }screen;
    
    // feature settings
    
    struct
    {
        
    }legit;
    
    struct
    {
        
    }rage;
    
    struct
    {
        
    }antiaim;
    
    struct
    {
        int  fov = 0;   // fov changer
        
        bool bhop = false;
        bool strafe = false;
    }misc;
    
    struct
    {
        // flags
        bool visible    = false; // visible check
        int  team_flags = 0;     // 0 = enemy only, 1 = team only, 2 = all
        
        // player visuals
        struct
        {
            bool box        = false;
            bool name       = false;
            bool health     = false;
            bool skeleton   = false;
            
            // example of how to use the multi, check the menu
            // also check prepare_settings() hooker.cpp
            multi example = {false, false, false}; // example1, example2, example3
        }player;
        
        struct
        {
            
        }chams;
        
        struct
        {
            
        }other;
    }visuals;
    
    struct
    {
        ImColor menu = ImColor(255, 255, 255, 255);
        
        struct
        {
            // color_t box = color_t::white, offscreen = color_t::blue;
            ImColor box = ImColor(255, 255, 255);
        }players;
        
        struct
        {
            ImColor players         = ImColor(255, 255, 255, 255);
            ImColor behind_walls    = ImColor(255, 255, 255, 255);
        }chams;
    }colors;
};
