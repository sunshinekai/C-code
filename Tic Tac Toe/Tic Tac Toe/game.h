#pragma once//预防头文件重复引入
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);
void ShowBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
int IsWin(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);