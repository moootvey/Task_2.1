#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "core.cpp"

void nameGame_screen();
void mainMenu_screen();
void playMenu_screen();
void aboutGame_screen();

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
	printf("1. ������\n");
	printf("2. � ����\n");
	printf("3. ����� �� ������� ����\n");
}

inline void playMenu_screen() {
	printf("\n\n\n");
	printf("1. ������� ������ ���������\n");
	printf("2. ��������� ���������\n");
	printf("3. ����� � ������� ����\n");
}

inline void aboutGame_screen() {
	nameGame_screen();
	printf("\n\n\n");
	printf("Powered by: Moootvey.\n");
	printf("������� ����� ������ ��� ������ � ������� ����...");
}

inline void createDude_screen() {
	nameGame_screen();
	printf("\n\n\n");
	printf("������� ��� ������ ���������: ");
}

inline void first_dialog() {

}

inline void weapon_show(struct weapon weapon) {
	printf("\n");
	printf("\n%s", weapon.weapon_class[0]);
	printf("\n��������� ����: %d", weapon.weapon_class[1]);
	printf("\n������������ ���������: %d", weapon.weapon_class[3]);
	printf("\n��������� �����: %d", weapon.weapon_class[4]);
	printf("\n���������: %d", weapon.weapon_class[5]);
}

inline void armor_show(struct armor armor) {
	printf("\n");
	printf("\n%s", armor.armor_class[0]);
	printf("\n������������ ���������: %d", armor.armor_class[2]);
	printf("\n���������: %d", armor.armor_class[3]);
}

inline void shield_show(struct shield shield) {
	printf("\n");
	printf("\n%s", shield.shield_class[0]);
	printf("\n������������ ���������: %d", shield.shield_class[2]);
	printf("\n���������� ������: %d", shield.shield_class[3]);
	printf("\n���������: %d", shield.shield_class[4]);

}