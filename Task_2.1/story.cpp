#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
#include "print_console.cpp"

#include <Windows.h>
#include <stdio.h>


static int delay = 20;  // �������� ����� ������� � ������������� 50 - ���������, �� ��������

void printTextByLetter(const char* text, int delay) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        printf("%c", text[i]);
        fflush(stdout);  // ������� �������� �����, ����� ����� ��� ������� �����
        Sleep(delay * 1);  // �������� � �������������
    }
}

//void start_text() {
//    int delay = 20;  // �������� ����� ������� � �������������
//}

int dialog_choose() {
    printf("\n������� ������� ������: ");
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
    const char* phase_one_1 = "��� 1: ������ ���� �����...";
    printTextByLetter(phase_one_1, delay);
    printf("\n");
    const char* phase_one_2 = "������ �������� ���� ����� ������������ ������������ � ��������, ������, ���� ��������� ������� ��������� ��������� ��� �����������...";
    printTextByLetter(phase_one_2, delay);
    printf("\n");
    const char* phase_one_3 = "��� �������� 4 ���� �����, ����� �� ����� ����������� ����� �������, ��� � ������� �������. �� ������� ������ � ���������� ��������� ������� �������� ����������.";
    printTextByLetter(phase_one_3, delay);
    printf("\n");
    const char* phase_one_4 = "							���� �� ������� �������� ������ ������ 15.06";
    printTextByLetter(phase_one_4, delay);
    printf("\n");
    paper_end_screen();
}

void first_phase_walk() {
    const char* phase_one_5 = "- ���, ������ � ����� �� ����������, �� ���������... ��, ������ �������� ���������� ������. � ��� ��� �� �����? ������� �� ������ ������ �����. ���� ����� ����������, ����� �� ��� ��������� ��� ����. �� � ��� ������� ����, � �� ����� ������� �������...";
    printTextByLetter(phase_one_5, delay);
    printf("\n");
    const char* phase_one_6 = "1. ����� � ���������� �������.";
    printTextByLetter(phase_one_6, delay);
    printf("\n");
    int choose = dialog_choose();
    if (choose == 1 || choose == 2 || choose == 3) {
        system("cls");
        const char* phase_one_7 = "� ���� ������, � ������ ��������� ����� ���� ���-�� �� ������� �������? �� �� ��� �������, � � ���� ����� ������-��.";
        printTextByLetter(phase_one_7, delay);
        printf("\n");
        const char* phase_one_8 = "1. ���� ������.";
        printTextByLetter(phase_one_8, delay);
        printf("\n");
    }
    choose = dialog_choose();
    if (choose == 1 || choose == 2 || choose == 3) {
        system("cls");
        const char* phase_one_9 = "������� � ����� �� ����.";
        printTextByLetter(phase_one_9, delay);
        printf("\n");
        const char* phase_one_10 = "1. ����������� � �����.";
        printTextByLetter(phase_one_10, delay);
        printf("\n");
        const char* phase_one_11 = "2. ���������� ���������� ����� ����.";
        printTextByLetter(phase_one_11, delay);
        printf("\n");
    }
    choose = dialog_choose();
    if (choose == 1) {
        system("cls");
        const char* phase_one_12 = "*���-���*...";
        printTextByLetter(phase_one_12, delay);
        printf("\n");
        const char* phase_one_13 = "*������ 2 ������* � ��� ����������? ����� ����� ���-��? �� ���� �� �������, ������ ���� ������ � ����� � ���� ����� ������� ��� �� ������. ������ ��������� ���������� � ���� ����� ����.";
        printTextByLetter(phase_one_13, delay);
        printf("\n");
        const char* phase_one_14 = "1. ���������� ����� ����.";
        printTextByLetter(phase_one_14, delay);
        printf("\n");
        choose = dialog_choose();
        system("cls");
    }
    else {
        system("cls");
    }
    const char* phase_one_15 = "����� ��� � ����������� ����� ���� � ����� ��������, �� ����� ���� �� �������� � �� �����.";
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