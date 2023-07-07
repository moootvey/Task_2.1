#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
#include "print_console.cpp"
#include "profile_file.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

static int count_dudes = 0;

static struct dude* main_profile;

void mainMenu_choose();
void about_game();
void play_game();
void nameGame_screen();
void playMenu_screen();
void aboutGame_screen();
void mainMenu_screen();
void create_dude();
void ultra_man(struct dude create_player);
void ultra_ork(struct dude create_player);
void ultra_dvarf(struct dude create_player);
void ultra_elf(struct dude create_player);
void load_dude(struct dude* load_player, int count);
void strat_game(struct dude* player);


inline void mainMenu_choose() {
	int selected = 0;
	int keyPressed;

	bool main = true;
	while (main) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выберете пункт меню: \n");
		printf("%s Играть\n", (selected == 0) ? "> " : "  ");
		printf("%s О игре\n", (selected == 1) ? "> " : "  ");
		printf("%s Выйти на рабочий стол\n", (selected == 2) ? "> " : "  ");

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
				play_game();
				main = false;
				break;
			case 1:
				about_game();
				main = false;
				break;
			case 2:
				exit(1);
				main = false;
				break;
			}
		}
	}
}

inline void mainMenu() {
	system("cls");
	nameGame_screen();
	mainMenu_screen();
	mainMenu_choose();
}

inline void strat_game(struct dude* player) {
	main_profile = player;
	printf("\n\n\n%s\n", main_profile[0].dude_name[0]);
	printf("%d %d %d %d\n", main_profile[0].dude_skills.dude_charisma, main_profile[0].dude_skills.dude_power, main_profile[0].dude_skills.dude_intelligence, main_profile[0].dude_skills.dude_close_combat);
	printf("%s\n", (char*)main_profile[0].dude_name[1]);
	printf("%s", main_profile[0].dude_ultra_abilities[1]);

	
}

inline void about_game() {
	system("cls");
	aboutGame_screen();
	char exitAbout_point;
	do {
		exitAbout_point = _getch();
		switch (exitAbout_point)
		{
		default:
			mainMenu();
			break;
		}
	} while (1);
}

inline void play_game() {
	int selected = 0;
	int keyPressed;
	int count;
	char filename[] = "players.dat";
	struct dude* load_player;

	bool play = true;
	while (play) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выберете пункт меню: \n");
		printf("%s Создать нового персонажа\n", (selected == 0) ? "> " : "  ");
		printf("%s Загрузить персонажа\n", (selected == 1) ? "> " : "  ");
		printf("%s Выйти в главное меню\n", (selected == 2) ? "> " : "  ");

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
				create_dude();
				play = false;
				break;
			case 1:
				count = check_file1();
				printf("\n%d", count);
				load_player = load_players(filename);
				load_dude(load_player, count);
				play = false;
				break;
			case 2:
				mainMenu();
				play = false;
				break;
			}
		}
	}
}

inline void load_dude(struct dude* load_player, int count) {
	int selected = 0;
	int keyPressed;

	bool load = true;
	while (load) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выберете персонажа: \n");
		for (int i = 0; i < count; i++) {
			printf("%s Структура %d: id = %s, value = %d\n", (selected == i) ? "> " : "  ", i + 1, load_player[i].dude_name, load_player[i].dude_skills.dude_charisma);
		}
		printf("%s Выйти в главное меню", (selected == 4) ? "> " : "  ");
		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < count-1) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
			switch (selected) {
			case 0:
				strat_game(&load_player[0]);
				//start_game(load_player);
				load = false;
				break;
			case 1:
				//start_game(load_player);
				load = false;
				break;
			case 2:
				//start_game(load_player);
				load = false;
				break;
			case 3:
				mainMenu();
				load = false;
				break;
			}
		}
	}
}

inline void create_dude() {
	system("cls");
	nameGame_screen();
	printf("\n\n\n");
	struct dude create_player;
	char name_player[] = "";
	printf("Введите имя своего персонажа (Максимум 10 символов): ");
	scanf_s("%s", create_player.dude_name[0], sizeof(create_player.dude_name[0]));
	int pointsTotal = 10;
	int pointsRemaining = pointsTotal;
	int categoryPoints[4] = { 0, 0, 0, 0 };
	int selected = 0;
	int keyPressed;
	bool points = true;

	while (points) {
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		// Вывод пунктов меню
		printf("Распределите очки способностей:\n");
		printf("%s 1. Харизма: %d очков\n", (selected == 0) ? "> " : "  ", categoryPoints[0]);
		printf("%s 2. Сила: %d очков\n", (selected == 1) ? "> " : "  ", categoryPoints[1]);
		printf("%s 3. Интеллект: %d очков\n", (selected == 2) ? "> " : "  ", categoryPoints[2]);
		printf("%s 4. Ближний бой: %d очков\n", (selected == 3) ? "> " : "  ", categoryPoints[3]);
		printf("Осталось очков: %d\n", pointsRemaining);

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 3) {
			selected++;
		}
		else if (keyPressed == KEY_LEFT && categoryPoints[selected] > 0) {
			categoryPoints[selected]--;
			pointsRemaining++;
		}
		else if (keyPressed == KEY_RIGHT && pointsRemaining > 0) {
			categoryPoints[selected]++;
			pointsRemaining--;
		}
		else if (keyPressed == KEY_ENTER) {
			points = false;
			break;
		}
	}
	create_player.dude_skills.dude_charisma = categoryPoints[0];
	create_player.dude_skills.dude_power = categoryPoints[1];
	create_player.dude_skills.dude_intelligence = categoryPoints[2];
	create_player.dude_skills.dude_close_combat = categoryPoints[3];

	char man[] = "Человек";
	char ork[] = "Орк";
	char dvarf[] = "Дварф";
	char elf[] = "Эльф";
	selected = 0;

	bool species = true;
	while (species) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выберете расу персонажа\n");
		printf("%s Человек\n", (selected == 0) ? "> " : "  ");
		printf("%s Орк\n", (selected == 1) ? "> " : "  ");
		printf("%s Дварф\n", (selected == 2) ? "> " : "  ");
		printf("%s Эльф\n", (selected == 3) ? "> " : "  ");

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
				strcpy((char*)create_player.dude_name[1], man);
				species = false;
				ultra_man(create_player);
				break;
			case 1:
				strcpy((char*)create_player.dude_name[1], ork);
				species = false;
				ultra_ork(create_player);
				break;
			case 2:
				strcpy((char*)create_player.dude_name[1], dvarf);
				species = false;
				ultra_dvarf(create_player);
				break;
			case 3:
				strcpy((char*)create_player.dude_name[1], elf);
				species = false;
				ultra_elf(create_player);
				break;
			}
		}
	}
	printf("\n\n\n%s\n", create_player.dude_name[0]);
	printf("%d %d %d %d\n", create_player.dude_skills.dude_charisma, create_player.dude_skills.dude_power, create_player.dude_skills.dude_intelligence, create_player.dude_skills.dude_close_combat);
	printf("%s\n", (char*)create_player.dude_name[1]);
}

inline void ultra_man(struct dude create_player) {
	char first[] = "Мастер меча";
	char second[] = "Целительство";
	char third[] = "Стратегический ум";
	char fourth[] = "Быстрое восстановление";
	char fifth[] = "Адаптивность";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выбранная раса - Человек.\n");
		printf("Выберете способность Вашего персонажа: \n");
		printf("%s Мастер меча: Высокая мастерство владения мечом, позволяющее наносить сильные удары.\n", (selected == 0) ? "> " : "  ");
		printf("%s Целительство: Способность лечить себя, восстанавливая здоровье.\n", (selected == 1) ? "> " : "  ");
		printf("%s Стратегический ум: Повышенная тактическая гибкость и способность планировать действия в бою.\n", (selected == 2) ? "> " : "  ");
		printf("%s Быстрое восстановление: Быстрое восстановление выносливости после длительных сражений.\n", (selected == 3) ? "> " : "  ");
		printf("%s Адаптивность: Быстрая адаптация к различным видам оружия и доспехов, что позволяет использовать разные стили боя.\n", (selected == 4) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
			switch (selected) {
			case 0:
				strcpy((char*)create_player.dude_ultra_abilities[1], first);
				ultra = false;
				break;
			case 1:
				strcpy((char*)create_player.dude_ultra_abilities[1], second);
				ultra = false;
				break;
			case 2:
				strcpy((char*)create_player.dude_ultra_abilities[1], third);
				ultra = false;
				break;
			case 3:
				strcpy((char*)create_player.dude_ultra_abilities[1], fourth);
				ultra = false;
				break;
			case 4:
				strcpy((char*)create_player.dude_ultra_abilities[1], fifth);
				ultra = false;
				break;
			}
		}
	}
	printf("\n\n\n%s\n", create_player.dude_name[0]);
	printf("%d %d %d %d\n", create_player.dude_skills.dude_charisma, create_player.dude_skills.dude_power, create_player.dude_skills.dude_intelligence, create_player.dude_skills.dude_close_combat);
	printf("%s\n", (char*)create_player.dude_name[1]);
	printf("%s", create_player.dude_ultra_abilities[1]);
	char filename[] = "players.dat";
	save_player(filename, &create_player);
	strat_game(&create_player);
}

inline void ultra_ork(struct dude create_player) {
	char first[] = "Берсеркерская ярость";
	char second[] = "Племенные связи";
	char third[] = "Повышенная выносливость";
	char fourth[] = "Темная магия";
	char fifth[] = "Пугающий вид";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выбранная раса - Орк.\n");
		printf("Выберете способность Вашего персонажа: \n");
		printf("%s Берсеркерская ярость: При входе в ярость орк получает временный бонус к силе и сопротивляемости.\n", (selected == 0) ? "> " : "  ");
		printf("%s Племенные связи: Орк может вызывать помощь союзников из своего племени для поддержки в бою.\n", (selected == 1) ? "> " : "  ");
		printf("%s Повышенная выносливость: Орк обладает большим запасом выносливости, что позволяет ему дольше сражаться без усталости.\n", (selected == 2) ? "> " : "  ");
		printf("%s Темная магия: Орк может использовать некоторые формы темной магии для атаки и защиты.\n", (selected == 3) ? "> " : "  ");
		printf("%s Пугающий вид: Орк может испугать противников своим внушительным внешним видом, временно лишая их способности сражаться.\n", (selected == 4) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
			switch (selected) {
			case 0:
				strcpy((char*)create_player.dude_ultra_abilities[1], first);
				ultra = false;
				break;
			case 1:
				strcpy((char*)create_player.dude_ultra_abilities[1], second);
				ultra = false;
				break;
			case 2:
				strcpy((char*)create_player.dude_ultra_abilities[1], third);
				ultra = false;
				break;
			case 3:
				strcpy((char*)create_player.dude_ultra_abilities[1], fourth);
				ultra = false;
				break;
			case 4:
				strcpy((char*)create_player.dude_ultra_abilities[1], fifth);
				ultra = false;
				break;
			}
		}
	}
	printf("\n\n\n%s\n", create_player.dude_name[0]);
	printf("%d %d %d %d\n", create_player.dude_skills.dude_charisma, create_player.dude_skills.dude_power, create_player.dude_skills.dude_intelligence, create_player.dude_skills.dude_close_combat);
	printf("%s\n", (char*)create_player.dude_name[1]);
	printf("%s", create_player.dude_ultra_abilities[1]);
	strat_game(&create_player);
}

inline void ultra_dvarf(struct dude create_player) {
	char first[] = "Кузнечное мастерство";
	char second[] = "Каменная кожа";
	char third[] = "Горное зрение";
	char fourth[] = "Устойчивость к ядам";
	char fifth[] = "Скрытность в горах";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выбранная раса - Дварф.\n");
		printf("Выберете способность Вашего персонажа: \n");
		printf("%s Кузнечное мастерство: Дварфы мастера кузнечного дела и могут создавать уникальное оружие и доспехи.\n", (selected == 0) ? "> " : "  ");
		printf("%s Каменная кожа: Повышенная защита благодаря каменной коже, позволяющая снижать получаемый урон.\n", (selected == 1) ? "> " : "  ");
		printf("%s Горное зрение: Дварфы обладают превосходным ночным зрением, что помогает им в темных подземельях.\n", (selected == 2) ? "> " : "  ");
		printf("%s Устойчивость к ядам: Дварфы имеют высокую устойчивость к ядам и отравлениям.\n", (selected == 3) ? "> " : "  ");
		printf("%s Скрытность в горах: Дварфы могут легко скрываться и передвигаться в горных местностях, обладая превосходной подвижностью.\n", (selected == 4) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
			switch (selected) {
			case 0:
				strcpy((char*)create_player.dude_ultra_abilities[1], first);
				ultra = false;
				break;
			case 1:
				strcpy((char*)create_player.dude_ultra_abilities[1], second);
				ultra = false;
				break;
			case 2:
				strcpy((char*)create_player.dude_ultra_abilities[1], third);
				ultra = false;
				break;
			case 3:
				strcpy((char*)create_player.dude_ultra_abilities[1], fourth);
				ultra = false;
				break;
			case 4:
				strcpy((char*)create_player.dude_ultra_abilities[1], fifth);
				ultra = false;
				break;
			}
		}
	}
	printf("\n\n\n%s\n", create_player.dude_name[0]);
	printf("%d %d %d %d\n", create_player.dude_skills.dude_charisma, create_player.dude_skills.dude_power, create_player.dude_skills.dude_intelligence, create_player.dude_skills.dude_close_combat);
	printf("%s\n", (char*)create_player.dude_name[1]);
	printf("%s", create_player.dude_ultra_abilities[1]);
	strat_game(&create_player);
}

inline void ultra_elf(struct dude create_player) {
	char first[] = "Лук и стрелы";
	char second[] = "Иллюзия";
	char third[] = "Природная связь";
	char fourth[] = "Скорость и грация";
	char fifth[] = "Исцеление природой";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// Вывод пунктов меню
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("Выбранная раса - Эльф.\n");
		printf("Выберете способность Вашего персонажа: \n");
		printf("%s Лук и стрелы: Мастерство владения луком и стрелами, позволяющее эльфам атаковать врагов на расстоянии.\n", (selected == 0) ? "> " : "  ");
		printf("%s Иллюзия: Эльфы могут создавать иллюзии и обманывать врагов, сбивая их с толку.\n", (selected == 1) ? "> " : "  ");
		printf("%s Природная связь: Эльфы обладают глубокой связью с природой и могут вызывать силы природы для помощи в бою.\n", (selected == 2) ? "> " : "  ");
		printf("%s Скорость и грация: Эльфы обладают высокой скоростью и гибкостью, позволяющими им быстро уклоняться от атак.\n", (selected == 3) ? "> " : "  ");
		printf("%s Исцеление природой: Эльфы могут использовать силы природы для исцеления ран и восстановления здоровья.\n", (selected == 4) ? "> " : "  ");

		// Получение нажатой клавиши
		keyPressed = _getch();

		// Обработка нажатой клавиши
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// Выполнение действия для выбранного пункта
			switch (selected) {
			case 0:
				strcpy((char*)create_player.dude_ultra_abilities[1], first);
				ultra = false;
				break;
			case 1:
				strcpy((char*)create_player.dude_ultra_abilities[1], second);
				ultra = false;
				break;
			case 2:
				strcpy((char*)create_player.dude_ultra_abilities[1], third);
				ultra = false;
				break;
			case 3:
				strcpy((char*)create_player.dude_ultra_abilities[1], fourth);
				ultra = false;
				break;
			case 4:
				strcpy((char*)create_player.dude_ultra_abilities[1], fifth);
				ultra = false;
				break;
			}
		}
	}
	printf("\n\n\n%s\n", create_player.dude_name[0]);
	printf("%d %d %d %d\n", create_player.dude_skills.dude_charisma, create_player.dude_skills.dude_power, create_player.dude_skills.dude_intelligence, create_player.dude_skills.dude_close_combat);
	printf("%s\n", (char*)create_player.dude_name[1]);
	printf("%s", create_player.dude_ultra_abilities[1]);
	strat_game(&create_player);
}