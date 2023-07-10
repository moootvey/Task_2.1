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
	printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
	int selected = 0;
	int keyPressed;
	man->money_bag = 1000;

	bool shop = true;
	while (shop) {
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
		printf("%s Оружие\n", (selected == 0) ? "> " : "  ");
		printf("%s Щиты\n", (selected == 1) ? "> " : "  ");
		printf("%s Доспехи\n", (selected == 2) ? "> " : "  ");
		printf("%s Артефакты\n", (selected == 3) ? "> " : "  ");
		printf("%s Зелья\n", (selected == 4) ? "> " : "  ");
		printf("%s Стартовый набор!!!\n", (selected == 5) ? "> " : "  ");
		printf("%s Прочие предметы\n", (selected == 6) ? "> " : "  ");
		printf("\nЗолотых моент: %d", man->money_bag);

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 6) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите тип оружия:\n");
		printf("%s Клинковове оружие\n", (selected == 0) ? "> " : "  ");
		printf("%s Лук\n", (selected == 1) ? "> " : "  ");
		printf("%s Топоры\n", (selected == 2) ? "> " : "  ");
		printf("%s Посохи\n", (selected == 3) ? "> " : "  ");
		printf("%s Молоты\n", (selected == 4) ? "> " : "  ");
		printf("%s Вернуться к выбору категории товара\n", (selected == 5) ? "> " : "  ");
		printf("\nЗолотых моент: %d", man->money_bag);

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выбирите щит, который вы желаете приобрести:\n");
		printf("%s Круглый деревянный щит\n", (selected == 0) ? "> " : "  ");
		printf("%s Тяжелый железный щит\n", (selected == 1) ? "> " : "  ");
		printf("%s Широкий стальной щит\n", (selected == 2) ? "> " : "  ");
		printf("%s Вернуться к выбору категории товара\n", (selected == 3) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выбирите щит, который вы желаете приобрести:\n");
		printf("%s Легкая кожанная броня\n", (selected == 0) ? "> " : "  ");
		printf("%s Кольчужная броня\n", (selected == 1) ? "> " : "  ");
		printf("%s Тяжелая платиновая броня\n", (selected == 2) ? "> " : "  ");
		printf("%s Вернуться к выбору категории товара\n", (selected == 3) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
	printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
		printf("%s Оружие\n", (selected == 0) ? "> " : "  ");
		printf("%s Щиты\n", (selected == 1) ? "> " : "  ");
		printf("%s Доспехи\n", (selected == 2) ? "> " : "  ");
		printf("%s Артефакты\n", (selected == 3) ? "> " : "  ");
		printf("%s Зелья\n", (selected == 4) ? "> " : "  ");
		printf("%s Прочие предметы\n", (selected == 5) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
	printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
		printf("%s Оружие\n", (selected == 0) ? "> " : "  ");
		printf("%s Щиты\n", (selected == 1) ? "> " : "  ");
		printf("%s Доспехи\n", (selected == 2) ? "> " : "  ");
		printf("%s Артефакты\n", (selected == 3) ? "> " : "  ");
		printf("%s Зелья\n", (selected == 4) ? "> " : "  ");
		printf("%s Прочие предметы\n", (selected == 5) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
	printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
	int selected = 0;
	int keyPressed;
	bool shop = true;
	while (shop) {
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Привет! Я местный торговец. Не желаешь приобрести что-то?\n");
		printf("%s Оружие\n", (selected == 0) ? "> " : "  ");
		printf("%s Щиты\n", (selected == 1) ? "> " : "  ");
		printf("%s Доспехи\n", (selected == 2) ? "> " : "  ");
		printf("%s Артефакты\n", (selected == 3) ? "> " : "  ");
		printf("%s Зелья\n", (selected == 4) ? "> " : "  ");
		printf("%s Прочие предметы\n", (selected == 5) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите клинковое оружие, которое вы желаете приобрести:\n");
		printf("%s Меч Света\n", (selected == 0) ? "> " : "  ");
		printf("%s Кинжал скрытности\n", (selected == 1) ? "> " : "  ");
		printf("%s Экскалибур\n", (selected == 2) ? "> " : "  ");
		printf("%s Стальной двуручный меч\n", (selected == 3) ? "> " : "  ");
		printf("%s Стальной клинок\n", (selected == 4) ? "> " : "  ");
		printf("%s Вернуться к выбору категории оружия\n", (selected == 5) ? "> " : "  ");
		printf("\nЗолотых моент: %d", man->money_bag);

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 5) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите лук, который вы желаете приобрести:\n");
		printf("%s Лук охотника\n", (selected == 0) ? "> " : "  ");
		printf("%s Боевой Лук\n", (selected == 1) ? "> " : "  ");
		printf("%s Лук снайпера\n", (selected == 2) ? "> " : "  ");
		printf("%s Вернуться к выбору категории оружия\n", (selected == 3) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите топрор, который вы желаете приобрести:\n");
		printf("%s Топор дровосека\n", (selected == 0) ? "> " : "  ");
		printf("%s Боевой топор\n", (selected == 1) ? "> " : "  ");
		printf("%s Вернуться к выбору категории оружия\n", (selected == 2) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите посох, который вы желаете приобрести:\n");
		printf("%s Волшебный посох\n", (selected == 0) ? "> " : "  ");
		printf("%s Пламенный посох\n", (selected == 1) ? "> " : "  ");
		printf("%s Вернуться к выбору категории оружия\n", (selected == 2) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		system("cls");
		printf("\n\n\n");
		printf("Выберите молот, который вы желаете приобрести:\n");
		printf("%s Двуручный молот\n", (selected == 0) ? "> " : "  ");
		printf("%s Кувалда хаоса\n", (selected == 1) ? "> " : "  ");
		printf("%s Вернуться к выбору категории оружия\n", (selected == 2) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 2) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
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
		// Вывод пунктов меню
		printf("\nЗолотых моент: %d", man->money_bag);
		printf("\n\n");
		printf("Нажмите 'b' для покупки предмета, чтобы выйти в меню выбора оружия нажмите 'q'...\n");
		// Получение нажатой клавиши
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
		// Вывод пунктов меню
		printf("\nЗолотых моент: %d", man->money_bag);
		printf("\n\n");
		printf("Нажмите 'b' для покупки предмета, чтобы выйти в меню выбора оружия нажмите 'q'...\n");
		// Получение нажатой клавиши
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
		// Вывод пунктов меню
		printf("\nЗолотых моент: %d", man->money_bag);
		printf("\n\n");
		printf("Нажмите 'b' для покупки предмета, чтобы выйти в меню выбора оружия нажмите 'q'...\n");
		// Получение нажатой клавиши
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
	printf("Стоимость: %d\nДенег осталось: %d\n", cost, man->money_bag);
	//printf("%s\nНаносимый урон: %d\nМаксимальная прочность: %d\nДистанция атаки: %d\nСтоимость: %d", man.dude_weapon.weapon_class[0], man.dude_weapon.weapon_class[1], man.dude_weapon.weapon_class[3], man.dude_weapon.weapon_class[4], man.dude_weapon.weapon_class[5]);

}

inline void compare(int cost, struct shop* man) {
	if (cost > man->money_bag){
		printf("\nУ вас недостаточно моент для покупки этого предмета!");
		printf("\nНажмите на любую клавишу, чтобы вернуться в меню выбора оружия...");
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