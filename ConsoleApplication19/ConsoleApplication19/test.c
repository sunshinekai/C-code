#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Menu()
{
	printf("**************************\n");
	printf("****欢迎来到三子棋游戏****\n");
	printf("**********0.exit**********\n");
	printf("**********1.play**********\n");
	printf("**************************\n");
}
void game()
{
	int ret = 0;
	char board[3][3] = { 0 };
	InitBoard(board, 3, 3);
	ShowBoard(board, 3, 3);
	printf("==========================\n");
	while (1)
	{
		PlayerMove(board, 3, 3);
		ret = IsWin(board, 3, 3);
		if (ret != ' ')
		{
			break;
		}
		ShowBoard(board, 3, 3);
		ComputerMove(board, 3, 3);
		ret = IsWin(board, 3, 3);
		if (ret != ' ')
		{
			break;
		}
		ShowBoard(board, 3, 3);
	}
	if (ret == 'O')
	{
		printf("你赢了\n");
	}
	if (ret == 'X')
	{
		printf("你输了\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		printf("请输入你的操作:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("游戏退出\n");
			break;
		case 1:
			game();
			break;
		default:
			break;
		}
	} while (input);
	return 0;
}