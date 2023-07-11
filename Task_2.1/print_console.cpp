#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"

#include <stdio.h>
#include <stdlib.h>


void nameGame_screen();
void mainMenu_screen();
void playMenu_screen();
void aboutGame_screen();
//void sword_screen();
//void bow_screen();
//void axe_screen();
//void stick_screen();
//void hammer_screen();
//void shield_screen();
//void armor_screen();
//void weapon_show(struct weapon weapon);
//void armor_show(struct armor armor);
//void shield_show(struct shield shield);

inline void nameGame_screen() {
	printf(" ___                 _        _    _                         _                                   _   \n");
	printf("| _ \\ ___ __ __ ___ | | _  _ | |_ (_) ___  _ _         __ _ | |_        ___ _  _  _ _   ___ ___ | |_ \n");
	printf("|   // -_)\\ \V // _ \\| || || ||  _|| |/ _ \\| ' \\       / _` ||  _|      (_-/| || || ' \\ (_-// -_)|  _|\n");
	printf("|_|_\\\\___| \\_/ \\___/|_| \\_._| \\__||_|\\___/|_||_|      \\__/_| \\__|      /__/ \\_._||_||_|/__/\\___| \\__|\n");
}

inline void sword_screen() {
	system("cls");
	printf("            _");
	printf("\n _         | |");
	printf("\n| | _______| |---------------------------------------------\\");
	printf("\n|:-)_______|==[]============================================>");
	printf("\n|_|        | |---------------------------------------------/");
	printf("\n           |_|");
}

inline void bow_screen() {
	system("cls");
	printf("   (");
	printf("\n    \\");
	printf("\n     )");
	printf("\n##-------->");
	printf("\n     )");
	printf("\n    /");
	printf("\n   (");
}

inline void axe_screen() {
	system("cls");
	printf("  ,  /\\  .  ");
	printf("\n //`-||-'\\\\ ");
	printf("\n(| -=||=- |)");
	printf("\n \\\\,-||-.// ");
	printf("\n  `  ||  '  ");
	printf("\n     ||     ");
	printf("\n     ||     ");
	printf("\n     ||     ");
	printf("\n     ||     ");
	printf("\n     ||     ");
	printf("\n     ()");
}

inline void stick_screen() {
	system("cls");
	printf("  ____");
	printf("\n./=**=\\.");
	printf("\n(|-**-|)");
	printf("\n \\____/");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ||");
	printf("\n   ()");
}

inline void hammer_screen() {
	system("cls");
	printf("  __        __");
	printf("\n||  \\      /  ||");
	printf("\n||   \\_()_/   ||");
	printf("\n||   |    |   ||");
	printf("\n||   |    |   ||");
	printf("\n||   |____|   ||");
	printf("\n||   / || \\   ||");
	printf("\n||__/  ||  \\__||");
	printf("\n       ||");
	printf("\n       ||");
	printf("\n       XX");
	printf("\n       XX");
	printf("\n       XX");
	printf("\n       XX");
	printf("\n       OO");
	printf("\n       `'");
	printf("\n");
}

inline void shield_screen() {
	system("cls");
	printf("  |`-._/\\_.-`|");
	printf("\n  |    ||    |");
	printf("\n  |___o()o___|");
	printf("\n  |__((<>))__|");
	printf("\n  \\   o\\/o   /");
	printf("\n   \\   ||   /");
	printf("\n    \\  ||  /");
	printf("\n     '.||.'");
	printf("\n       ``");
}

inline void armor_screen() {
	system("cls");
	printf("==jgs==!====!=====!=====!====!===!===!=====!===!===!====");
	printf("\n      /`\\__/`\\   /`\\   /`\\  |~| |~|  /)=I=(\\  /`'''`\\");
	printf("\n     |        | |   `'`   | | | | |  |  :  | |   :   | ");
	printf("\n     '-|    |-' '-|     |-' )/\\ )/\\  |  T  \\ '-| : |-'");
	printf("\n       |    |     |     |  / \\// \\/  (  |\\  |  '---'");
	printf("\n       '.__.'     '.___.'  \\_/ \\_/   |  |/  /");
	printf("\n                                     |  /  /");
	printf("\n                                     |  \\ /");
	printf("\n                                     '--'`");
}

inline void mainMenu_screen() {
	printf("\n\n\n");
	printf("1. Играть\n");
	printf("2. О игре\n");
	printf("3. Выйти на рабочий стол\n");
}

inline void playMenu_screen() {
	printf("\n\n\n");
	printf("1. Создать нового персонажа\n");
	printf("2. Загрузить персонажа\n");
	printf("3. Выйти в главное меню\n");
}

inline void aboutGame_screen() {
	nameGame_screen();
	printf("\n\n\n");
	printf("Powered by: Moootvey.\n");
	printf("Нажмите любую кнопку для выхода в главное меню...");
}

inline void createDude_screen() {
	nameGame_screen();
	printf("\n\n\n");
	printf("Введите имя своего персонажа: ");
}

inline void first_dialog() {

}

inline void weapon_show(struct weapon weapon) {
	printf("\n");
	printf("\n%s", weapon.weapon_class);
	printf("\nНаносимый урон: %d", weapon.damage);
	printf("\nМаксимальная прочность: %d", weapon.MAX_durability);
	printf("\nДистанция атаки: %d", weapon.distance);
	printf("\nСтоимость: %d", weapon.cost);
}

inline void armor_show(struct armor armor) {
	printf("\n");
	printf("\n%s", armor.armor_class);
	printf("\nМаксимальная прочность: %d", armor.MAX_durability);
	printf("\nСтоимость: %d", armor.cost);
}

inline void shield_show(struct shield shield) {
	printf("\n");
	printf("\n%s", shield.shield_class);
	printf("\nМаксимальная прочность: %d", shield.MAX_durability);
	printf("\nКоэффицент зациты: %d", shield.shield_koef);
	printf("\nСтоимость: %d", shield.cost);

}

inline void paper_end_screen() {
	printf("\n|--__---\\--\\\\									  _______________??//");
	printf("\n	     \\-\\----____-					 ___________----_/");
	printf("\n			--__--___-				/");
	printf("\n				  \\__-__+______\\	       /");
	printf("\n						\\___=-+_______/");
}