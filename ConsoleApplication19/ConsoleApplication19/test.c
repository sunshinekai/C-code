#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Menu()
{
	printf("**************************\n");
	printf("****��ӭ������������Ϸ****\n");
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
		printf("��Ӯ��\n");
	}
	if (ret == 'X')
	{
		printf("������\n");
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		printf("��������Ĳ���:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("��Ϸ�˳�\n");
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