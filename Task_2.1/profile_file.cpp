#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"
//#include "core.cpp"

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAX_STRUCTURES 3



inline int file_boot1(char* filename) {
    char* c;    // ��� ���������� ��������� ��������
    int m = sizeof(int);    // ������� ���� ������� ��� ��������� ������� �������
    int n;  // ���������� �������� � �������

    FILE* fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error occured while opening file\n");
    }
    // �������� ������ ��� �������� ���������� ������
    int* ptr_count = malloc(m);
    // ��������� ���������� ��������
    c = (char*)ptr_count;
    // ���� �� ������� m ����, ��������� ���� � ���������� ���� ��� ������� �������
    while (m > 0 && (*c = getc(fp)) != EOF)
    {
        c++;
        m--;
    }
    //�������� ����� ���������
    n = *ptr_count;
    printf("%d", n);
    free(ptr_count);    // ����������� ������
    return n;
}

inline int check_file1() {
    char filename[] = "players.dat";
    FILE* file = fopen(filename, "rb");
    int count = 0;

    if (file != NULL) {
        fseek(file, 0, SEEK_END); // ���������� ��������� � ����� �����
        long fileSize = ftell(file); // �������� ������� ������� ���������, ������� ������������� ������� �����
        count = fileSize / sizeof(struct dude); // ��������� ���������� ��������

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
        rewind(file); // ���������� ��������� � ������ �����

        if (count > 0) {
            player = (struct dude*)malloc(sizeof(struct dude) * count);
            if (player != NULL) {
                fread(player, sizeof(struct dude), count, file);
            }
        }
        else {
            printf("���� � ������������ ���� ��� �� ������. �������� ��������� ��� ������ ����.\n");
            Sleep(2000);  // ���������������� ���������� ��������� �� 2 �������
            // ��������� ������� � ������� mainMenu_N ��� ������ ����������� �������
            //mainMenu_N();  // ������ �������� � ������� mainMenu_N
            return NULL;
        }

        fclose(file);
    }
    else {
        printf("�� ������� ������� ����: %s\n", filename);
    }

    return player;
}

// �������, ������� ������� ���������� ���� � �������� � ���������� ���������
inline bool ask_for_overwrite() {
    printf("������ ������������ ���� �� ������������ ��������? (y/n): ");
    char choice;
    scanf_s(" %c", &choice);
    return (choice == 'y' || choice == 'Y');
}

inline int save_player(char* filename, struct dude* player) {
    FILE* file = fopen(filename, "rb+");

    if (file != NULL) {
        // ����������� ������������� ���������� ��������
        struct dude existingPlayers[MAX_STRUCTURES];
        int count = 0;

        // ������ ������������ �������� �� �����
        count = check_file1();

        // ��������, ���������� �� ������������ ���������� ��������
        if (count < MAX_STRUCTURES) {
            // ������ ����� ���������
            fseek(file, count * sizeof(struct dude), SEEK_SET);
            fwrite(player, sizeof(struct dude), 1, file);
            fclose(file);
            printf("������ ������� ��������� � ����: %s\n", filename);
        }
        else {
            fclose(file);

            bool structCH = true;
            while (structCH) {
                if (ask_for_overwrite()) {
                    // �������������� ���� �� ������������ ��������
                    printf("�������� ����� ��������� ��� ���������� (1-%d): ", MAX_STRUCTURES);
                    int index;
                    scanf_s("%d", &index);

                    if (index >= 1 && index <= MAX_STRUCTURES) {
                        file = fopen(filename, "rb+");
                        fseek(file, (index - 1) * sizeof(struct dude), SEEK_SET);
                        fwrite(player, sizeof(struct dude), 1, file);
                        fclose(file);
                        printf("��������� ������� ������������ � �����: %s\n", filename);
                    }
                    else {
                        printf("�������� ����� ���������.\n");
                    }
                    structCH = false;
                }
                else {
                    printf("���������� ������������ ���������� �������� � �����: %s\n", filename);
                    printf("������� � ����...");
                    Sleep(2000);
                    structCH = false;
                    return 0;
                }
            }
        }
    }
    else {
        printf("�� ������� ������� ����: %s\n", filename);
    }
    return 1;
}