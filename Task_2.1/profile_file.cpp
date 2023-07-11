#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
//#include "core.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_STRUCTURES 3



inline int file_boot1(char* filename) {
    char* c;    // для считывания отдельных символов
    int m = sizeof(int);    // сколько надо считать для получения размера массива
    int n;  // количество структур в массиве

    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
    }
    // выделяем память для хранения количества данных
    int* ptr_count = malloc(m);
    // считываем количество структур
    c = (char*)ptr_count;
    // пока не считаем m байт, сохраняем байт в выделенный блок для размера массива
    while (m > 0 && (*c = getc(fp)) != EOF)
    {
        c++;
        m--;
    }
    //получаем число элементов
    n = *ptr_count;
    printf("%d", n);
    free(ptr_count);    // освобождаем память
    return n;
}

inline int check_file1() {
    char filename[] = "players.dat";
    FILE* file = fopen(filename, "rb");
    int count = 0;

    if (file != NULL) {
        fseek(file, 0, SEEK_END); // Перемещаем указатель в конец файла
        long fileSize = ftell(file); // Получаем текущую позицию указателя, которая соответствует размеру файла
        count = fileSize / sizeof(struct dude); // Вычисляем количество структур

        fclose(file);
    }
    return count;
}

inline struct dude* load_players(const char* filename) {
    int count;
    FILE* file = fopen(filename, "rb");
    struct dude* player = NULL;

    if (file != NULL) {
        fseek(file, 0, SEEK_END);
        long fileSize = ftell(file);
        count = fileSize / sizeof(struct dude);
        rewind(file); // Перемещаем указатель в начало файла

        if (count > 0) {
            player = (struct dude*)malloc(sizeof(struct dude) * count);
            if (player != NULL) {
                fread(player, sizeof(struct dude), count, file);
            }
        }
        else {
            printf("Файл с сохранениями пуст или не создан. Создайте персонажа для начала игры.\n");
            Sleep(2000);  // Приостанавливаем выполнение программы на 2 секунды
            // Выполняем переход к функции mainMenu_N или другой необходимой функции
            //mainMenu_N();  // Пример перехода к функции mainMenu_N
            return NULL;
        }

        fclose(file);
    }
    else {
        printf("Не удалось открыть файл: %s\n", filename);
    }

    return player;
}

// Функция, которая выводит диалоговое окно с вопросом о перезаписи структуры
inline bool ask_for_overwrite() {
    printf("Хотите перезаписать одну из существующих структур? (y/n): ");
    char choice;
    scanf_s(" %c", &choice);
    return (choice == 'y' || choice == 'Y');
}

inline int save_player(char* filename, struct dude* player) {
    FILE* file = fopen(filename, "rb+");

    if (file != NULL) {
        // Определение максимального количества структур
        struct dude existingPlayers[MAX_STRUCTURES];
        int count = 0;

        // Чтение существующих структур из файла
        count = check_file1();

        // Проверка, достигнуто ли максимальное количество структур
        if (count < MAX_STRUCTURES) {
            // Запись новой структуры
            fseek(file, count * sizeof(struct dude), SEEK_SET);
            fwrite(player, sizeof(struct dude), 1, file);
            fclose(file);
            printf("Данные успешно сохранены в файл: %s\n", filename);
        }
        else {
            fclose(file);

            bool structCH = true;
            while (structCH) {
                if (ask_for_overwrite()) {
                    // Перезаписываем одну из существующих структур
                    printf("Выберите номер структуры для перезаписи (1-%d): ", MAX_STRUCTURES);
                    int index;
                    scanf_s("%d", &index);

                    if (index >= 1 && index <= MAX_STRUCTURES) {
                        file = fopen(filename, "rb+");
                        fseek(file, (index - 1) * sizeof(struct dude), SEEK_SET);
                        fwrite(player, sizeof(struct dude), 1, file);
                        fclose(file);
                        printf("Структура успешно перезаписана в файле: %s\n", filename);
                    }
                    else {
                        printf("Неверный номер структуры.\n");
                    }
                    structCH = false;
                }
                else {
                    printf("Достигнуто максимальное количество структур в файле: %s\n", filename);
                    printf("Возврат в меню...");
                    Sleep(2000);
                    structCH = false;
                    return 0;
                }
            }
        }
    }
    else {
        printf("Не удалось открыть файл: %s\n", filename);
    }
    return 1;
}