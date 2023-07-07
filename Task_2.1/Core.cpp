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
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("�������� ����� ����: \n");
		printf("%s ������\n", (selected == 0) ? "> " : "  ");
		printf("%s � ����\n", (selected == 1) ? "> " : "  ");
		printf("%s ����� �� ������� ����\n", (selected == 2) ? "> " : "  ");

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
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("�������� ����� ����: \n");
		printf("%s ������� ������ ���������\n", (selected == 0) ? "> " : "  ");
		printf("%s ��������� ���������\n", (selected == 1) ? "> " : "  ");
		printf("%s ����� � ������� ����\n", (selected == 2) ? "> " : "  ");

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
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("�������� ���������: \n");
		for (int i = 0; i < count; i++) {
			printf("%s ��������� %d: id = %s, value = %d\n", (selected == i) ? "> " : "  ", i + 1, load_player[i].dude_name, load_player[i].dude_skills.dude_charisma);
		}
		printf("%s ����� � ������� ����", (selected == 4) ? "> " : "  ");
		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < count-1) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
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
	printf("������� ��� ������ ��������� (�������� 10 ��������): ");
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
		// ����� ������� ����
		printf("������������ ���� ������������:\n");
		printf("%s 1. �������: %d �����\n", (selected == 0) ? "> " : "  ", categoryPoints[0]);
		printf("%s 2. ����: %d �����\n", (selected == 1) ? "> " : "  ", categoryPoints[1]);
		printf("%s 3. ���������: %d �����\n", (selected == 2) ? "> " : "  ", categoryPoints[2]);
		printf("%s 4. ������� ���: %d �����\n", (selected == 3) ? "> " : "  ", categoryPoints[3]);
		printf("�������� �����: %d\n", pointsRemaining);

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
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

	char man[] = "�������";
	char ork[] = "���";
	char dvarf[] = "�����";
	char elf[] = "����";
	selected = 0;

	bool species = true;
	while (species) {
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("�������� ���� ���������\n");
		printf("%s �������\n", (selected == 0) ? "> " : "  ");
		printf("%s ���\n", (selected == 1) ? "> " : "  ");
		printf("%s �����\n", (selected == 2) ? "> " : "  ");
		printf("%s ����\n", (selected == 3) ? "> " : "  ");

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
	char first[] = "������ ����";
	char second[] = "������������";
	char third[] = "�������������� ��";
	char fourth[] = "������� ��������������";
	char fifth[] = "������������";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("��������� ���� - �������.\n");
		printf("�������� ����������� ������ ���������: \n");
		printf("%s ������ ����: ������� ���������� �������� �����, ����������� �������� ������� �����.\n", (selected == 0) ? "> " : "  ");
		printf("%s ������������: ����������� ������ ����, �������������� ��������.\n", (selected == 1) ? "> " : "  ");
		printf("%s �������������� ��: ���������� ����������� �������� � ����������� ����������� �������� � ���.\n", (selected == 2) ? "> " : "  ");
		printf("%s ������� ��������������: ������� �������������� ������������ ����� ���������� ��������.\n", (selected == 3) ? "> " : "  ");
		printf("%s ������������: ������� ��������� � ��������� ����� ������ � ��������, ��� ��������� ������������ ������ ����� ���.\n", (selected == 4) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
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
	char first[] = "������������� ������";
	char second[] = "��������� �����";
	char third[] = "���������� ������������";
	char fourth[] = "������ �����";
	char fifth[] = "�������� ���";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("��������� ���� - ���.\n");
		printf("�������� ����������� ������ ���������: \n");
		printf("%s ������������� ������: ��� ����� � ������ ��� �������� ��������� ����� � ���� � ����������������.\n", (selected == 0) ? "> " : "  ");
		printf("%s ��������� �����: ��� ����� �������� ������ ��������� �� ������ ������� ��� ��������� � ���.\n", (selected == 1) ? "> " : "  ");
		printf("%s ���������� ������������: ��� �������� ������� ������� ������������, ��� ��������� ��� ������ ��������� ��� ���������.\n", (selected == 2) ? "> " : "  ");
		printf("%s ������ �����: ��� ����� ������������ ��������� ����� ������ ����� ��� ����� � ������.\n", (selected == 3) ? "> " : "  ");
		printf("%s �������� ���: ��� ����� �������� ����������� ����� ������������ ������� �����, �������� ����� �� ����������� ���������.\n", (selected == 4) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
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
	char first[] = "��������� ����������";
	char second[] = "�������� ����";
	char third[] = "������ ������";
	char fourth[] = "������������ � ����";
	char fifth[] = "���������� � �����";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("��������� ���� - �����.\n");
		printf("�������� ����������� ������ ���������: \n");
		printf("%s ��������� ����������: ������ ������� ���������� ���� � ����� ��������� ���������� ������ � �������.\n", (selected == 0) ? "> " : "  ");
		printf("%s �������� ����: ���������� ������ ��������� �������� ����, ����������� ������� ���������� ����.\n", (selected == 1) ? "> " : "  ");
		printf("%s ������ ������: ������ �������� ������������ ������ �������, ��� �������� �� � ������ �����������.\n", (selected == 2) ? "> " : "  ");
		printf("%s ������������ � ����: ������ ����� ������� ������������ � ���� � �����������.\n", (selected == 3) ? "> " : "  ");
		printf("%s ���������� � �����: ������ ����� ����� ���������� � ������������� � ������ ����������, ������� ������������ ������������.\n", (selected == 4) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
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
	char first[] = "��� � ������";
	char second[] = "�������";
	char third[] = "��������� �����";
	char fourth[] = "�������� � ������";
	char fifth[] = "��������� ��������";
	int selected = 0;
	int keyPressed;

	bool ultra = true;
	while (ultra) {
		// ����� ������� ����
		system("cls");
		nameGame_screen();
		printf("\n\n\n");
		printf("��������� ���� - ����.\n");
		printf("�������� ����������� ������ ���������: \n");
		printf("%s ��� � ������: ���������� �������� ����� � ��������, ����������� ������ ��������� ������ �� ����������.\n", (selected == 0) ? "> " : "  ");
		printf("%s �������: ����� ����� ��������� ������� � ���������� ������, ������ �� � �����.\n", (selected == 1) ? "> " : "  ");
		printf("%s ��������� �����: ����� �������� �������� ������ � �������� � ����� �������� ���� ������� ��� ������ � ���.\n", (selected == 2) ? "> " : "  ");
		printf("%s �������� � ������: ����� �������� ������� ��������� � ���������, ������������ �� ������ ���������� �� ����.\n", (selected == 3) ? "> " : "  ");
		printf("%s ��������� ��������: ����� ����� ������������ ���� ������� ��� ��������� ��� � �������������� ��������.\n", (selected == 4) ? "> " : "  ");

		// ��������� ������� �������
		keyPressed = _getch();

		// ��������� ������� �������
		if (keyPressed == KEY_UP && selected > 0) {
			selected--;
		}
		else if (keyPressed == KEY_DOWN && selected < 4) {
			selected++;
		}
		else if (keyPressed == KEY_ENTER) {
			// ���������� �������� ��� ���������� ������
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