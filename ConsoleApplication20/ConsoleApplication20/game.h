#pragma once      //Ԥ��ͷ�ļ��ظ�����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINENUM 10 //��ʼ10����

void SetMine(char Mine[ROWS][COLS], int row, int col);      //������
void c_mine(char Mine[ROWS][COLS], int row, int col);             //��ʼ��
void Print(char Mine[ROWS][COLS], int row, int col);              //��ӡ
void c_show(char Mine[ROWS][COLS], int row, int col);             //��ʼ��
int FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col);     //����