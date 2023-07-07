#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "core.cpp"
#include "shop.cpp"

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	//mainMenu();
	main_shop();
}