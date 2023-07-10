#pragma once
#define _CRT_SECURE_NO_WARNINGS

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


void weapon_shop(struct shop* man);
void weapon_shop_swords(struct shop* man);
void weapon_shop_bows(struct shop* man);
void weapon_shop_axes(struct shop* man);
void weapon_shop_sticks(struct shop* man);
void weapon_shop_hammers(struct shop* man);
void buy_weapon(struct weapon weapons, struct shop* man);
void fin(int cost, struct shop* man);
void compare(int cost, struct shop* man);
void shield_shop(struct shop* man);
void armor_shop(struct shop* man);
void buy_shield(struct shield shields, struct shop* man);
void buy_armor(struct armor armors, struct shop* man);
struct shop main_shop_(struct shop* man);
void start_pack(struct shop* man);

//inline struct shop init_shop_struct() {
//	struct shop* man = malloc(sizeof(struct shop));
//	return *man;
//}
//
//inline struct shop start_shop() {
//	main_shop_(init_shop_struct());
//}

inline struct shop main_shop_(struct shop* man) {
	//struct dude* man = malloc(sizeof(struct dude))
	system("cls");
	printf("\n\n\n");
	printf("������! � ������� ��������. �� ������� ���������� ���-��?\n");
	int selected = 0;
	int keyPressed;
	man->money_bag = 1000;

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
		printf("%s ��������� �����!!!\n", (selected == 5) ? "> " : "  ");
		printf("%s ������ ��������\n", (selected == 6) ? "> " : "  ");
		printf("\n������� �����: %d", man->money_bag);

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 6) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
			switch (selected) {
			case 0:
				weapon_shop(man);
				shop = false;
				break;
			case 1:
				shield_shop(man);
				shop = false;
				break;
			case 2:
				armor_shop(man);
				shop = false;
				break;
			case 3:

				shop = false;
				break;
			case 4:

				shop = false;
				break;
			case 5:
				start_pack(man);
				shop = false;
				break;
			case 6:
				shop = false;
				break;
			}
		}
	}
	return  *man;
}

inline void weapon_shop(struct shop* man) {
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
		printf("\n������� �����: %d", man->money_bag);

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
				weapon_shop_swords(man);
				weapon_shop = false;
				break;
			case 1:
				weapon_shop_bows(man);
				weapon_shop = false;
				break;
			case 2:
				weapon_shop_axes(man);
				weapon_shop = false;
				break;
			case 3:
				weapon_shop_sticks(man);
				weapon_shop = false;
				break;
			case 4:
				weapon_shop_hammers(man);
				weapon_shop = false;
				break;
			case 5:
				main_shop_(man);
				weapon_shop = false;
				break;
			}
		}
	}
}

inline void shield_shop(struct shop* man) {
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
				buy_shield(sheld_player[0], man);
				flag = false;
				break;
			case 1:
				shield_screen();
				shield_show(sheld_player[1]);
				buy_shield(sheld_player[1], man);
				flag = false;
				break;
			case 2:
				shield_screen();
				shield_show(sheld_player[2]);
				buy_shield(sheld_player[2], man);
				flag = false;
				break;
			case 3:
				main_shop_(man);
				flag = false;
				break;
			}
		}
	}
}

inline void armor_shop(struct shop* man) {
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
				buy_armor(armor_clothes[0], man);
				flag = false;
				break;
			case 1:
				armor_screen();
				armor_show(armor_clothes[1]);
				buy_armor(armor_clothes[1], man);
				flag = false;
				break;
			case 2:
				armor_screen();
				armor_show(armor_clothes[2]);
				buy_armor(armor_clothes[2], man);
				flag = false;
				break;
			case 3:
				main_shop_(man);
				flag = false;
				break;
			}
		}
	}
}

inline void artefact_shop(struct shop* man) {
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
				mainMenu_(man);
				shop = false;
				break;
			}
		}
	}
}

inline void potion_shop(struct shop* man) {
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
				mainMenu_(man);
				shop = false;
				break;
			}
		}
	}
}

inline void drop_shop(struct shop* man) {
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
				mainMenu_(man);
				shop = false;
				break;
			}
		}
	}
}

inline void weapon_shop_swords(struct shop* man) {
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
		printf("\n������� �����: %d", man->money_bag);

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
				buy_weapon(sword[0], man);
				flag = false;
				break;
			case 1:
				sword_screen();
				weapon_show(sword[1]);
				buy_weapon(sword[1], man);
				flag = false;
				break;
			case 2:
				sword_screen();
				weapon_show(sword[2]);
				buy_weapon(sword[2], man);
				flag = false;
				break;
			case 3:
				sword_screen();
				weapon_show(sword[3]);
				buy_weapon(sword[3], man);
				break;
			case 4:
				sword_screen();
				weapon_show(sword[4]);
				buy_weapon(sword[4], man);
				flag = false;
				break;
			case 5:
				weapon_shop(man);
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_bows(struct shop* man) {
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
				buy_weapon(bows[0], man);
				flag = false;
				break;
			case 1:
				bow_screen();
				weapon_show(bows[1]);
				buy_weapon(bows[1], man);
				flag = false;
				break;
			case 2:
				bow_screen();
				weapon_show(bows[2]);
				buy_weapon(bows[2], man);
				flag = false;
				break;
			case 3:
				weapon_shop(man);
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_axes(struct shop* man) {
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
				buy_weapon(axes[0], man);
				flag = false;
				break;
			case 1:
				axe_screen();
				weapon_show(axes[1]);
				buy_weapon(axes[1], man);
				flag = false;
				break;
			case 2:
				weapon_shop(man);
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_sticks(struct shop* man) {
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
				buy_weapon(sticks[0], man);
				flag = false;
				break;
			case 1:
				stick_screen();
				weapon_show(sticks[1]);
				buy_weapon(sticks[1], man);
				flag = false;
				break;
			case 2:
				weapon_shop(man);
				flag = false;
				break;
			}
		}
	}
}

inline void weapon_shop_hammers(struct shop* man) {
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
				buy_weapon(hammers[0], man);
				flag = false;
				break;
			case 1:
				hammer_screen();
				weapon_show(hammers[1]);
				buy_weapon(hammers[1], man);
				flag = false;
				break;
			case 2:
				weapon_shop(man);
				flag = false;
				break;
			}
		}
	}
}

inline void buy_weapon(struct weapon weapons, struct shop* man) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man->money_bag);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = weapons.cost;
			compare(cost, man);
			fin(cost, man);
			man->shop_weapon = weapons;
			man->money_bag -= cost;
			weapon_shop(man);
			flag = false;
			break;
		case 'q':
			weapon_shop(man);
			flag = false;
			break;
		}
	}
}

inline void buy_shield(struct shield shields, struct shop* man) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man->money_bag);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = shields.cost;
			compare(cost, man);
			fin(cost, man);
			man->shop_shield = shields;
			man->money_bag -= cost;
			shield_shop(man);
			flag = false;
			break;
		case 'q':
			shield_shop(man);
			flag = false;
			break;
		}
	}
}

inline void buy_armor(struct armor armors, struct shop* man) {
	int keyPressed;
	int cost;
	bool flag = true;
	while (flag) {
		// ����� ������� ����
		printf("\n������� �����: %d", man->money_bag);
		printf("\n\n");
		printf("������� 'b' ��� ������� ��������, ����� ����� � ���� ������ ������ ������� 'q'...\n");
		// ��������� ������� �������
		keyPressed = _getch();
		switch (keyPressed) {
		case 'b':
			cost = armors.cost;
			compare(cost, man);
			fin(cost, man);
			man->shop_armor = armors;
			man->money_bag -= cost;
			armor_shop(man);
			flag = false;
			break;
		case 'q':
			armor_shop(man);
			flag = false;
			break;
		}
	}
}

inline void fin(int cost, struct shop* man) {
	system("cls");
	printf("���������: %d\n����� ��������: %d\n", cost, man->money_bag);
	//printf("%s\n��������� ����: %d\n������������ ���������: %d\n��������� �����: %d\n���������: %d", man.dude_weapon.weapon_class[0], man.dude_weapon.weapon_class[1], man.dude_weapon.weapon_class[3], man.dude_weapon.weapon_class[4], man.dude_weapon.weapon_class[5]);

}

inline void compare(int cost, struct shop* man) {
	if (cost > man->money_bag){
		printf("\n� ��� ������������ ����� ��� ������� ����� ��������!");
		printf("\n������� �� ����� �������, ����� ��������� � ���� ������ ������...");
		system("pause");
		weapon_shop(man);
	}
}

inline void start_pack(struct shop* man) {
	int cost = sword[4].cost;
	compare(cost, man);
	//fin(cost, man);
	man->shop_weapon = sword[4];
	man->money_bag -= cost;
	cost = sheld_player[1].cost;
	compare(cost, man);
	//fin(cost, man);
	man->shop_shield = sheld_player[1];
	man->money_bag -= cost;
	cost = armor_clothes[1].cost;
	compare(cost, man);
	//fin(cost, man);
	man->shop_armor = armor_clothes[1];
	man->money_bag -= cost;
	main_shop_(man);

}