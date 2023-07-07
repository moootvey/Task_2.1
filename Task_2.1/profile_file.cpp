#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "headers.h"

#include <stdio.h>
#include <stdlib.h>



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

inline void save_player(char* filename, struct dude* player) {
    FILE* file = fopen(filename, "ab");

    if (file != NULL) {
        fwrite(player, sizeof(struct dude), 1, file);
        fclose(file);
        printf("������ ������� ��������� � ����: %s\n", filename);
    }
    else {
        printf("�� ������� ������� ����: %s\n", filename);
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
        rewind(file); // ���������� ��������� � ������ �����

        player = (struct dude*)malloc(sizeof(struct dude) * (count));
        if (player != NULL) {
            fread(player, sizeof(struct dude), (count), file);
        }

        fclose(file);
    }

    return player;
}