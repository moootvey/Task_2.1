#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

typedef struct weapon		//Оружие в наличии
{
	char* weapon_class;			//Навзвание оружия; Урон от него; Прочность оружия; Максимальная прочность; Рабочая дистанция оружия; Стоимость оружия
	int damage;
	int durability;
	int MAX_durability;
	int distance;
	int cost;
};

typedef struct shield		//Щит
{
	char* shield_class;			//Название; Максимальная прочность; Прочность; Стоимость; Коэф. защиты
	int durability;
	int MAX_durability;
	int shield_koef;
	int cost;
};

typedef struct armor		//Броня
{
	char* armor_class;			//Название брони; Текущее значение брони; Максимальная броня; Стоимость брони
	int durability;
	int MAX_durability;
	int cost;
};

typedef struct artifact		//Артифакт
{
	char* artifact_name[8];			//Наименование артефакта; Стоимость; Улучшение харизмы; Улучшение силы для лука или булавы или типо; Улучшение интеллекта для крафта; Улучшение ближнего боя;Увеличение скорости регена здоровья; Учеличение максимального здоровья
};

typedef struct drop			//Предметы для крафта
{
	char* drop_class[2];			//Наименование ресурса; Стоимость в магазине
};

//typedef struct shop			//Магазин
//{
//	char* shop_weapon[6];			//Оружие у торговца
//	char* shop_armor[4];			//Броня
//	char* shop_drop[10];			//Дроп
//	char* shop_shield[5];			//Щит
//	char* shop_potion[6];			//Зелья
//	char* shop_artifact[8];			//Артифакты
//	char* shop_axe[3];				//топорик)
//};

typedef struct potion		//Зелья
{
	char* potion_class[6];			//Название; Получение регенерации; Увеличение максимального здоровья; Дополнительная энергия; Стоимость; Время действия
};

typedef struct stats		//Статистика игрока
{
	bool dude_win_game;				//Игра пройдена?
	int dude_win_enemys;			//Сколько победил противников
	int dude_open_cases;			//Сколько кейсов открыл
	int dude_age;					//Возраст
	int dude_money;					//Количество денег
	int dude_healt;					//Здоровье на данный момент
	int dude_MAX_health;			//Максимальное здоровье
};

typedef struct skills		//Распределенные очки сопосбностей
{
	int dude_charisma;				//Харизма
	int dude_power;					//Сила для лука или булавы или типо
	int dude_intelligence;			//Интеллект для крафта
	int dude_close_combat;			//Ближний бой
};

typedef struct dude			//Главвный герой
{
	char* dude_name[2][10];			//Имя персонажа
	char* dude_ultra_abilities[2][100];//Ульта
	struct weapon dude_weapon;		//Оружие персонажа
	struct armor dude_armor;		//Броня персонажа
	struct shield dude_shield;		//Щит персонажа
	struct stats dude_stats;		//Распределенные очки сопосбностей
	struct skills dude_skills;		//Статистика игрока
	int dude_distance;
};

typedef struct shop
{
	struct weapon shop_weapon;		//Оружие персонажа
	struct armor shop_armor;		//Броня персонажа
	struct shield shop_shield;		//Щит персонажа
	int money_bag;
};

//typedef struct dude_inventory
//{
//	
//} dude_inventory;

typedef struct enemy		//Рядовой противник
{
	char* enemy_name[2][10];		//Имя врага
	char* enemy_ultra_abilities[4];	//Ульта
	int enemy_health;				//Здоровье на данный момент
	int enemy_MAX_health;			//Максимальное здоровье
	struct weapon enemy_weapon;		//Оружие врага
	struct armor enemy_armor;		//Броня врага
	struct shield enemy_shield;		//Щит врага
	char* enemy_drop_items[2];		//Предметы, которые выпадут из поверженного врага
	double enemy_distance;			//Дистанция до противника
	double enemy_agressive;			//Агрессия на персонажа (от нее зависит сила атаки и прочее)
};

typedef struct main_enemy	//Босс
{
	char* main_enemy_name[2][10];	//Имя главного врага
	char* main_enemy_ultra_abilities[4];//Ульта
	int main_enemy_health;			//Здоровья на данный момент
	int main_enemy_MAX_health;		//Максимально здоровье
	struct weapon main_enemy_weapon;//Оружие главного врага
	struct armor main_enemy_armor;	//Броня главного врага
	struct shield main_enemy_shield;//Щит главного врага
	char* main_enemy_drop_items[2];	//Предметы, которые выпадут из поверженного врага
	double main_enemy_distance;		//Дистанция до противника
	double main_enemy_agressive;	//Агрессия на персонажа (от нее зависит сила атаки и прочее)
};

typedef struct companion	//Компаньон
{
	char* companion_name[2];		//Имя компаньона
	char* companion_ultra_abilities[4];//Ульта
	int companion_health;			//Здоровье на данный момент
	int companion_MAX_health;		//Максимальное здоровье
	struct weapon companion_weapon;	//Оружие компаньона
	struct armor companion_armor;	//Броня компаньона
	struct shield companion_shield;	//Щит компаньона
};