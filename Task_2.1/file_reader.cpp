#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"

#include <stdio.h>

void action() {
    printf("action");
}

void lol() {
    printf("lol");
}

void kek() {
    printf("kek");
}

int Main_reader() {
    FILE* file;
    char filename[100] = "text.txt";
    char ch;
    int insideOption = 0;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '{') {
            dialog_reader(file, ch);
        }

    }
}

int dialog_reader(FILE* file, char* ch) {
    int choice;
    int currentOption = 1;
    int optionStart = 0;
    int optionEnd = 0;
    int insideOption = 0;

    // Считываем и обрабатываем символы из файла
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '{') {
            if (!insideOption) {
                insideOption = 1;
                optionStart = currentOption;
            }
        }
        else if (ch == '\n') {
            if (insideOption) {
                insideOption = 0;
                optionEnd = currentOption;
                currentOption++;
            }
        }
        else if (insideOption) {
            printf("%c", ch);
        }
    }

    // Закрываем файл
    fclose(file);

    // Запрос пользовательского выбора
    printf("\n\nВыберите один из вариантов (1-%d): ", currentOption - 1);
    scanf("%d", &choice);
    char filename[100] = "text.txt";
    // Открываем файл снова для выполнения выбранного варианта
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    currentOption = 1;
    insideOption = 0;

    // Считываем и обрабатываем символы из файла для выбранного варианта
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '{') {
            if (!insideOption) {
                insideOption = 1;
            }
        }
        else if (ch == '\n') {
            if (insideOption) {
                insideOption = 0;
                currentOption++;
            }
        }
        else if (currentOption == choice && insideOption) {
            printf("%c", ch);
        }
    }

    // Закрываем файл
    fclose(file);

    return 0;
}