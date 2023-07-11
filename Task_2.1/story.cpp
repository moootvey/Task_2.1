#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
#include "print_console.cpp"

#include <Windows.h>
#include <stdio.h>


static int delay = 20;  // Задержка между буквами в миллисекундах 50 - прикольно, но медленно

void printTextByLetter(const char* text, int delay) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        printf("%c", text[i]);
        fflush(stdout);  // Очищаем выходной буфер, чтобы текст был видимым сразу
        Sleep(delay * 1);  // Задержка в миллисекундах
    }
}

//void start_text() {
//    int delay = 20;  // Задержка между буквами в миллисекундах
//}

int dialog_choose() {
    printf("\nВведите выриант ответа: ");
    char keyPressed;
    keyPressed = _getch();
    switch (keyPressed) {
    case '1':
        return 1;
        break;
    case '2':
        return 2;
        break;
    case '3':
        return 3;
        break;
    }
}

void first_phase_book() {
    const char* phase_one_1 = "Акт 1: Раньше было лучше...";
    printTextByLetter(phase_one_1, delay);
    printf("\n");
    const char* phase_one_2 = "Раньше Аркантия была самым процветающим королевством в Эльмории, однако, одно маленькое событие разрушило абсолютно все государство...";
    printTextByLetter(phase_one_2, delay);
    printf("\n");
    const char* phase_one_3 = "Все началось 4 года назад, когда во главе королевства встал Моргант, орк с мрачным прошлым. Он захотел власти и подчинения абсолютно каждого существа королевста.";
    printTextByLetter(phase_one_3, delay);
    printf("\n");
    const char* phase_one_4 = "							Одна из страниц дневника некого Эдрика 15.06";
    printTextByLetter(phase_one_4, delay);
    printf("\n");
    paper_end_screen();
}

void first_phase_walk() {
    const char* phase_one_5 = "- Мда, видимо у ребят не получилось, не фартануло... Хм, листок выглядит достаточно старым. И что еще за Эдрик? Никогда не слышал такого имени. Надо найти старейшину, может он что расскажет про него. Да и про дневник тоже, а то такая интрига нависла...";
    printTextByLetter(phase_one_5, delay);
    printf("\n");
    const char* phase_one_6 = "1. Пойти к старейшине деревни.";
    printTextByLetter(phase_one_6, delay);
    printf("\n");
    int choose = dialog_choose();
    if (choose == 1 || choose == 2 || choose == 3) {
        system("cls");
        const char* phase_one_7 = "У меня вопрос, а почему старешина долже жить где-то на окраине деревни? Он же тут главный, а я идти устал вообще-то.";
        printTextByLetter(phase_one_7, delay);
        printf("\n");
        const char* phase_one_8 = "1. Идти дальше.";
        printTextByLetter(phase_one_8, delay);
        printf("\n");
    }
    choose = dialog_choose();
    if (choose == 1 || choose == 2 || choose == 3) {
        system("cls");
        const char* phase_one_9 = "Наконец я дошел до него.";
        printTextByLetter(phase_one_9, delay);
        printf("\n");
        const char* phase_one_10 = "1. Постучаться в дверь.";
        printTextByLetter(phase_one_10, delay);
        printf("\n");
        const char* phase_one_11 = "2. Попытаться проникнуть через окно.";
        printTextByLetter(phase_one_11, delay);
        printf("\n");
    }
    choose = dialog_choose();
    if (choose == 1) {
        system("cls");
        const char* phase_one_12 = "*Тук-Тук*...";
        printTextByLetter(phase_one_12, delay);
        printf("\n");
        const char* phase_one_13 = "*Прошло 2 минуты* А где старейшина? Опять уснул что-ли? Ну хотя не мудрено, каждый день ходить с рынка к себе домой никаких сил не хватит. Видимо придеться проникнуть к нему через окно.";
        printTextByLetter(phase_one_13, delay);
        printf("\n");
        const char* phase_one_14 = "1. Проникнуть через окно.";
        printTextByLetter(phase_one_14, delay);
        printf("\n");
        choose = dialog_choose();
        system("cls");
    }
    else {
        system("cls");
    }
    const char* phase_one_15 = "Может это и неправильно через окна в гости заходить, но ждать пока он выспится я не готов.";
    printTextByLetter(phase_one_15, delay);
    printf("\n");
}

void first_phase() {
    first_phase_book();
    Sleep(5000);
    system("cls");
    first_phase_walk();
}

void seckond_phase() {

}

void third_phase() {

}