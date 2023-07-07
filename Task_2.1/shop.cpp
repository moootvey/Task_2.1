#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
#include "print_console.cpp"

#include "weapon_class.cpp"
#include "shield_class.cpp"
#include "armor_class.cpp"

#include <stdio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13


void weapon_shop();
void weapon_shop_swords();
void weapon_shop_bows();
void weapon_shop_axes();
void weapon_shop_sticks();
void weapon_shop_hammers();
void buy_weapon(struct weapon weapons);
void fin(int cost);
void compare(int cost);
void shield_shop();
void armor_shop();
void buy_shield(struct shield shields);
void buy_armor(struct armor armors);

static struct dude man;

inline void main_shop() {
	system("cls");
	printf("\n\n\n");
	printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
	int selected = 0;
	int keyPressed;
	man.dude_stats.dude_money = 1000;

	bool shop = true;
	while (shop) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
		printf("%s ������\n", (selected == 0) ? "> " : "  ");
		printf("%s ����\n", (selected == 1) ? "> " : "  ");
		printf("%s �������\n", (selected == 2) ? "> " : "  ");
		printf("%s ���������\n", (selected == 3) ? "> " : "  ");
		printf("%s �����\n", (selected == 4) ? "> " : "  ");
		printf("%s ������ ��������\n", (selected == 5) ? "> " : "  ");
		printf("\n������� �����: %d", man.dude_stats.dude_money);

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				weapon_shop();
				shop = false;
				break;
			case 1:
				shield_shop();
				shop = false;
				break;
			case 2:
				armor_shop();
				shop = false;
				break;
			case 3:

				shop = false;
				break;
			case 4:

				shop = false;
				break;
			case 5:
				mainMenu();
				shop = false;
				break;
			}
		}
	}
}

inline void weapon_shop() {
	int selected = 0;
	int keyPressed;
	bool weapon_shop = true;
	while (weapon_shop) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ��� ������:\n");
		printf("%s ���������� ������\n", (selected == 0) ? "> " : "  ");
		printf("%s ���\n", (selected == 1) ? "> " : "  ");
		printf("%s ������\n", (selected == 2) ? "> " : "  ");
		printf("%s ������\n", (selected == 3) ? "> " : "  ");
		printf("%s ������\n", (selected == 4) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 5) ? "> " : "  ");
		printf("\n������� �����: %d", man.dude_stats.dude_money);

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				weapon_shop_swords();
				weapon_shop = false;
				break;
			case 1:
				weapon_shop_bows();
				weapon_shop = false;
				break;
			case 2:
				weapon_shop_axes();
				weapon_shop = false;
				break;
			case 3:
				weapon_shop_sticks();
				weapon_shop = false;
				break;
			case 4:
				weapon_shop_hammers();
				weapon_shop = false;
				break;
			case 5:
				main_shop();
				weapon_shop = false;
				break;
			}
		}
	}
}

inline void shield_shop() {
	system("cls");
	printf("\n\n\n");
	int selected = 0;
	int keyPressed;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ���, ������� �� ������� ����������:\n");
		printf("%s ������� ���������� ���\n", (selected == 0) ? "> " : "  ");
		printf("%s ������� �������� ���\n", (selected == 1) ? "> " : "  ");
		printf("%s ������� �������� ���\n", (selected == 2) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 3) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				shield_screen();
				shield_show(sheld_player[0]);
				buy_shield(sheld_player[0]);
				flag = false;
				break;
			case 1:
				shield_screen();
				shield_show(sheld_player[1]);
				buy_shield(sheld_player[1]);
				flag = false;
				break;
			case 2:
				shield_screen();
				shield_show(sheld_player[2]);
				buy_shield(sheld_player[2]);
				flag = false;
				break;
			case 3:
				main_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void armor_shop() {
	system("cls");
	printf("\n\n\n");
	int selected = 0;
	int keyPressed;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ���, ������� �� ������� ����������:\n");
		printf("%s ������ �������� �����\n", (selected == 0) ? "> " : "  ");
		printf("%s ���������� �����\n", (selected == 1) ? "> " : "  ");
		printf("%s ������� ���������� �����\n", (selected == 2) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 3) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				armor_screen();
				armor_show(armor_clothes[0]);
				buy_armor(armor_clothes[0]);
				flag = false;
				break;
			case 1:
				armor_screen();
				armor_show(armor_clothes[1]);
				buy_armor(armor_clothes[1]);
				flag = false;
				break;
			case 2:
				armor_screen();
				armor_show(armor_clothes[2]);
				buy_armor(armor_clothes[2]);
				flag = false;
				break;
			case 3:
				main_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void artefact_shop() {
	system("cls");
	printf("\n\n\n");
	printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
		printf("%s ������\n", (selected == 0) ? "> " : "  ");
		printf("%s ����\n", (selected == 1) ? "> " : "  ");
		printf("%s �������\n", (selected == 2) ? "> " : "  ");
		printf("%s ���������\n", (selected == 3) ? "> " : "  ");
		printf("%s �����\n", (selected == 4) ? "> " : "  ");
		printf("%s ������ ��������\n", (selected == 5) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:

				shop = false;
				break;
			case 1:

				shop = false;
				break;
			case 2:

				shop = false;
				break;
			case 3:

				shop = false;
				break;
			case 4:

				shop = false;
				break;
			case 5:
				mainMenu();
				shop = false;
				break;
			}
		}
	}
}

inline void potion_shop() {
	system("cls");
	printf("\n\n\n");
	printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
		printf("%s ������\n", (selected == 0) ? "> " : "  ");
		printf("%s ����\n", (selected == 1) ? "> " : "  ");
		printf("%s �������\n", (selected == 2) ? "> " : "  ");
		printf("%s ���������\n", (selected == 3) ? "> " : "  ");
		printf("%s �����\n", (selected == 4) ? "> " : "  ");
		printf("%s ������ ��������\n", (selected == 5) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:

				shop = false;
				break;
			case 1:

				shop = false;
				break;
			case 2:

				shop = false;
				break;
			case 3:

				shop = false;
				break;
			case 4:

				shop = false;
				break;
			case 5:
				mainMenu();
				shop = false;
				break;
			}
		}
	}
}

inline void drop_shop() {
	system("cls");
	printf("\n\n\n");
	printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
		printf("%s ������\n", (selected == 0) ? "> " : "  ");
		printf("%s ����\n", (selected == 1) ? "> " : "  ");
		printf("%s �������\n", (selected == 2) ? "> " : "  ");
		printf("%s ���������\n", (selected == 3) ? "> " : "  ");
		printf("%s �����\n", (selected == 4) ? "> " : "  ");
		printf("%s ������ ��������\n", (selected == 5) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:

				shop = false;
				break;
			case 1:

				shop = false;
				break;
			case 2:

				shop = false;
				break;
			case 3:

				shop = false;
				break;
			case 4:

				shop = false;
				break;
			case 5:
				mainMenu();
				shop = false;
				break;
			}
		}
	}
}

inline void weapon_shop_swords() {
	int selected = 0;
	int keyPressed;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ��������� ������, ������� �� ������� ����������:\n");
		printf("%s ��� �����\n", (selected == 0) ? "> " : "  ");
		printf("%s ������ ����������\n", (selected == 1) ? "> " : "  ");
		printf("%s ����������\n", (selected == 2) ? "> " : "  ");
		printf("%s �������� ��������� ���\n", (selected == 3) ? "> " : "  ");
		printf("%s �������� ������\n", (selected == 4) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 5) ? "> " : "  ");
		printf("\n������� �����: %d", man.dude_stats.dude_money);

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				sword_screen();
				weapon_show(sword[0]);
				buy_weapon(sword[0]);
				flag = false;
				break;
			case 1:
				sword_screen();
				weapon_show(sword[1]);
				buy_weapon(sword[1]);
				flag = false;
				break;
			case 2:
				sword_screen();
				weapon_show(sword[2]);
				buy_weapon(sword[2]);
				flag = false;
				break;
			case 3:
				sword_screen();
				weapon_show(sword[3]);
				buy_weapon(sword[3]);
				break;
			case 4:
				sword_screen();
				weapon_show(sword[4]);
				buy_weapon(sword[4]);
				flag = false;
				break;
			case 5:
				weapon_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_bows() {
	int selected = 0;
	int keyPressed;
	bool flag = true;
	//struct weapon swords[6] = {{ }};
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ���, ������� �� ������� ����������:\n");
		printf("%s ��� ��������\n", (selected == 0) ? "> " : "  ");
		printf("%s ������ ���\n", (selected == 1) ? "> " : "  ");
		printf("%s ��� ��������\n", (selected == 2) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 3) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				bow_screen();
				weapon_show(bows[0]);
				buy_weapon(bows[0]);
				flag = false;
				break;
			case 1:
				bow_screen();
				weapon_show(bows[1]);
				buy_weapon(bows[1]);
				flag = false;
				break;
			case 2:
				bow_screen();
				weapon_show(bows[2]);
				buy_weapon(bows[2]);
				flag = false;
				break;
			case 3:
				weapon_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_axes() {
	int selected = 0;
	int keyPressed;
	bool flag = true;
	//struct weapon swords[6] = {{ }};
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� ������, ������� �� ������� ����������:\n");
		printf("%s ����� ���������\n", (selected == 0) ? "> " : "  ");
		printf("%s ������ �����\n", (selected == 1) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 2) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				axe_screen();
				weapon_show(axes[0]);
				buy_weapon(axes[0]);
				flag = false;
				break;
			case 1:
				axe_screen();
				weapon_show(axes[1]);
				buy_weapon(axes[1]);
				flag = false;
				break;
			case 2:
				weapon_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_sticks() {
	int selected = 0;
	int keyPressed;
	bool flag = true;
	//struct weapon swords[6] = {{ }};
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� �����, ������� �� ������� ����������:\n");
		printf("%s ��������� �����\n", (selected == 0) ? "> " : "  ");
		printf("%s ��������� �����\n", (selected == 1) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 2) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				stick_screen();
				weapon_show(sticks[0]);
				buy_weapon(sticks[0]);
				flag = false;
				break;
			case 1:
				stick_screen();
				weapon_show(sticks[1]);
				buy_weapon(sticks[1]);
				flag = false;
				break;
			case 2:
				weapon_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_hammers() {
	int selected = 0;
	int keyPressed;
	bool flag = true;
	//struct weapon swords[6] = {{ }};
	while (flag) {
		// ����� ������� ����
		system("cls");
		printf("\n\n\n");
		printf("�������� �����, ������� �� ������� ����������:\n");
		printf("%s ��������� �����\n", (selected == 0) ? "> " : "  ");
		printf("%s ������� �����\n", (selected == 1) ? "> " : "  ");
		printf("%s ��������� � ������ ��������� ������\n", (selected == 2) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				hammer_screen();
				weapon_show(hammers[0]);
				buy_weapon(hammers[0]);
				flag = false;
				break;
			case 1:
				hammer_screen();
				weapon_show(hammers[1]);
				buy_weapon(hammers[1]);
				flag = false;
				break;
			case 2:
				weapon_shop();
				flag = false;
				break;
			}
		}
	}
}

inline void buy_weapon(struct weapon weapons) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man.dude_stats.dude_money);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = weapons.weapon_class[5];
			compare(cost);
			fin(cost);
			man.dude_weapon = weapons;
			man.dude_stats.dude_money -= cost;
			weapon_shop();
			flag = false;
			break;
		case 'q':
			weapon_shop();
			flag = false;
			break;
		}
	}
}

inline void buy_shield(struct shield shields) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man.dude_stats.dude_money);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = shields.shield_class[4];
			compare(cost);
			fin(cost);
			man.dude_shield = shields;
			man.dude_stats.dude_money -= cost;
			shield_shop();
			flag = false;
			break;
		case 'q':
			shield_shop();
			flag = false;
			break;
		}
	}
}

inline void buy_armor(struct armor armors) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man.dude_stats.dude_money);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = armors.armor_class[3];
			compare(cost);
			fin(cost);
			man.dude_armor = armors;
			man.dude_stats.dude_money -= cost;
			armor_shop();
			flag = false;
			break;
		case 'q':
			armor_shop();
			flag = false;
			break;
		}
	}
}

inline void fin(int cost) {
	system("cls");
	printf("���������: %d\n����� ��������: %d\n", cost, man.dude_stats.dude_money);
	printf("%s\n��������� ����: %d\n������������ ���������: %d\n��������� �����: %d\n���������: %d", man.dude_weapon.weapon_class[0], man.dude_weapon.weapon_class[1], man.dude_weapon.weapon_class[3], man.dude_weapon.weapon_class[4], man.dude_weapon.weapon_class[5]);

}

inline void compare(int cost) {
	if (cost > man.dude_stats.dude_money){
		printf("\n� ��� ������������ ����� ��� ������� ����� ��������!");
		printf("\n������� �� ����� �������, ����� ��������� � ���� ������ ������...");
		system("pause");
		weapon_shop();
	}
}