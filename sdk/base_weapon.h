/*
 * base_weapon.h
 */
#pragma once

class base_weapon_t : public base_attributable_item_t
{
public:
    
    bool is_weapon()
    {
        // todo
        return true;
    }
    
    int get_ammo()
    {
        return sdk_get_offset(int, base_combat_weapon, m_clip1);
    }
    
    float get_next_attack()
    {
        return sdk_get_offset(float, base_combat_weapon, m_next_primary_attack);
    }
    
    weapon_info_t* get_weapon_info()
    {
        // crashes
        typedef weapon_info_t*(*o_get_weapon_info)(void*);
        return getvfunc<o_get_weapon_info>(this, 516)(this);
    }
};

typedef base_weapon_t weapon_t;
