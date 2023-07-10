#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

typedef struct weapon		//������ � �������
{
	char* weapon_class;			//��������� ������; ���� �� ����; ��������� ������; ������������ ���������; ������� ��������� ������; ��������� ������
	int damage;
	int durability;
	int MAX_durability;
	int distance;
	int cost;
};

typedef struct shield		//���
{
	char* shield_class;			//��������; ������������ ���������; ���������; ���������; ����. ������
	int durability;
	int MAX_durability;
	int shield_koef;
	int cost;
};

typedef struct armor		//�����
{
	char* armor_class;			//�������� �����; ������� �������� �����; ������������ �����; ��������� �����
	int durability;
	int MAX_durability;
	int cost;
};

typedef struct artifact		//��������
{
	char* artifact_name[8];			//������������ ���������; ���������; ��������� �������; ��������� ���� ��� ���� ��� ������ ��� ����; ��������� ���������� ��� ������; ��������� �������� ���;���������� �������� ������ ��������; ���������� ������������� ��������
};

typedef struct drop			//�������� ��� ������
{
	char* drop_class[2];			//������������ �������; ��������� � ��������
};

//typedef struct shop			//�������
//{
//	char* shop_weapon[6];			//������ � ��������
//	char* shop_armor[4];			//�����
//	char* shop_drop[10];			//����
//	char* shop_shield[5];			//���
//	char* shop_potion[6];			//�����
//	char* shop_artifact[8];			//���������
//	char* shop_axe[3];				//�������)
//};

typedef struct potion		//�����
{
	char* potion_class[6];			//��������; ��������� �����������; ���������� ������������� ��������; �������������� �������; ���������; ����� ��������
};

typedef struct stats		//���������� ������
{
	bool dude_win_game;				//���� ��������?
	int dude_win_enemys;			//������� ������� �����������
	int dude_open_cases;			//������� ������ ������
	int dude_age;					//�������
	int dude_money;					//���������� �����
	int dude_healt;					//�������� �� ������ ������
	int dude_MAX_health;			//������������ ��������
};

typedef struct skills		//�������������� ���� ������������
{
	int dude_charisma;				//�������
	int dude_power;					//���� ��� ���� ��� ������ ��� ����
	int dude_intelligence;			//��������� ��� ������
	int dude_close_combat;			//������� ���
};

typedef struct dude			//�������� �����
{
	char* dude_name[2][10];			//��� ���������
	char* dude_ultra_abilities[2][100];//�����
	struct weapon dude_weapon;		//������ ���������
	struct armor dude_armor;		//����� ���������
	struct shield dude_shield;		//��� ���������
	struct stats dude_stats;		//�������������� ���� ������������
	struct skills dude_skills;		//���������� ������
	int dude_distance;
};

typedef struct shop
{
	struct weapon shop_weapon;		//������ ���������
	struct armor shop_armor;		//����� ���������
	struct shield shop_shield;		//��� ���������
	int money_bag;
};

//typedef struct dude_inventory
//{
//	
//} dude_inventory;

typedef struct enemy		//������� ���������
{
	char* enemy_name[2][10];		//��� �����
	char* enemy_ultra_abilities[4];	//�����
	int enemy_health;				//�������� �� ������ ������
	int enemy_MAX_health;			//������������ ��������
	struct weapon enemy_weapon;		//������ �����
	struct armor enemy_armor;		//����� �����
	struct shield enemy_shield;		//��� �����
	char* enemy_drop_items[2];		//��������, ������� ������� �� ������������ �����
	double enemy_distance;			//��������� �� ����������
	double enemy_agressive;			//�������� �� ��������� (�� ��� ������� ���� ����� � ������)
};

typedef struct main_enemy	//����
{
	char* main_enemy_name[2][10];	//��� �������� �����
	char* main_enemy_ultra_abilities[4];//�����
	int main_enemy_health;			//�������� �� ������ ������
	int main_enemy_MAX_health;		//����������� ��������
	struct weapon main_enemy_weapon;//������ �������� �����
	struct armor main_enemy_armor;	//����� �������� �����
	struct shield main_enemy_shield;//��� �������� �����
	char* main_enemy_drop_items[2];	//��������, ������� ������� �� ������������ �����
	double main_enemy_distance;		//��������� �� ����������
	double main_enemy_agressive;	//�������� �� ��������� (�� ��� ������� ���� ����� � ������)
};

typedef struct companion	//���������
{
	char* companion_name[2];		//��� ����������
	char* companion_ultra_abilities[4];//�����
	int companion_health;			//�������� �� ������ ������
	int companion_MAX_health;		//������������ ��������
	struct weapon companion_weapon;	//������ ����������
	struct armor companion_armor;	//����� ����������
	struct shield companion_shield;	//��� ����������
};