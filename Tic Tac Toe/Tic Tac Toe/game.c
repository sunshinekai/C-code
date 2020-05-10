#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', row*col *sizeof(char));
}


void ShowBoard(char board[ROW][COL], int row, int col)
{
	int i = 0; int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j<col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i<row - 1)
		{
			for (j = 0; j <col; j++)
			{
				printf("---");
				if (j<col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����ƶ�\n");
		printf("��ֱ��������е�����:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && y <= 3)
		{
			if (board[x - 1][y - 1] == ' ')//��ǰλ��û������
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("��λ���Ѿ����¹�����\n");
			}
		}
		else
		{
			printf("���겻�Ϸ�\n");
		}
	}
}


static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


int IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}//��
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}//��
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		{
			return board[0][0];
		}//�Խ���
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		{
			return board[0][2];
		}//�Խ���
		if (IsFull(board, row, col) == 1)
		{
			return 'Q';//ƽ��
		}
	}
	return ' ';//û��Ӯ�ң�û��ƽ��
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ƶ�\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			break;
		}
	}
}