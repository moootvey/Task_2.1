#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "core.cpp"

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	init_enemy_1();
	mainMenu_N();
	//main_shop();
	//choise_attack();

}