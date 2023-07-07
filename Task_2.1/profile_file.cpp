#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"

#include <stdio.h>
#include <stdlib.h>



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

inline void save_player(char* filename, struct dude* player) {
    FILE* file = fopen(filename, "ab");

    if (file != NULL) {
        fwrite(player, sizeof(struct dude), 1, file);
        fclose(file);
        printf("Данные успешно сохранены в файл: %s\n", filename);
    }
    else {
        printf("Не удалось открыть файл: %s\n", filename);
    }
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

        player = (struct dude*)malloc(sizeof(struct dude) * (count));
        if (player != NULL) {
            fread(player, sizeof(struct dude), (count), file);
        }

        fclose(file);
    }

    return player;
}