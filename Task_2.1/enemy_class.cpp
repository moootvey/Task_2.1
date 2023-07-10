#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "weapon_class.cpp"
#include "armor_class.cpp"
#include "shield_class.cpp"

#include <string.h>

static struct enemy enemy_1;

inline void init_enemy_1() {
    enemy_1.enemy_name[0][0] = _strdup("PIDORAS");
    enemy_1.enemy_health = 100;
    enemy_1.enemy_weapon = sword[1];
    enemy_1.enemy_armor = armor_clothes[1];
    enemy_1.enemy_shield = sheld_player[0];
    enemy_1.enemy_distance = 5;
    enemy_1.enemy_agressive = 1;

}