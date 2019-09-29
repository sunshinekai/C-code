#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void c_mine(char Mine[ROWS][COLS], int row, int col)            //��ʼ������
{
	memset(Mine, '0', row*col*sizeof(Mine[0][0]));
}
void c_show(char Mine[ROWS][COLS], int row, int col)
{
	memset(Mine, '*', row*col*sizeof(Mine[0][0]));
}
void Print(char Mine[ROWS][COLS], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	printf("--------------------\n");
	for ( i = 0; i <=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i <=row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", Mine[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}
static void moveMine(char Mine[ROWS][COLS], int x, int y)      //�ƶ���һ�βȵ�����
{
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % ROW + 1;
		b = rand() % COL + 1;
		if (Mine[a][b] != '1')
		{
			Mine[a][b] = '1';
			break;
		}
	}
	Mine[x][y] = '0';
}
void SetMine(char Mine[ROWS][COLS], int row, int col) //��������
{
	int count = MINENUM;
	int x = 0;
	int y = 0;
	while (count!=0)
	{
		x = rand() % row + 1;//[0,9)[1,10)
		y = rand() % col + 1;
		if (Mine[x][y] =='0')
		{
			Mine[x][y] = '1';
			count--;
		}
	}
}
static int GetMine(char Mine[ROWS][COLS], int x, int y) //ͳ������
{
	//'1'-'0'=1
	return  Mine[x - 1][y - 1]+
			Mine[x - 1][y]+
			Mine[x - 1][y + 1]+
			Mine[x][y - 1]+
			Mine[x][y + 1]+
			Mine[x + 1][y - 1]+
			Mine[x + 1][y]+
			Mine[x + 1][y + 1] - 8 * '0';
}
static int opeanMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int x, int y)    //�õݹ�ʵ��չ��δ֪����
{
	if (GetMine(Mine, x, y) == 0)
	{
		Show[x][y] = '0';
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL&&Show[x - 1][y - 1] == '*')
			opeanMine(Mine, Show, x - 1, y - 1);
		if ((x) >= 1 && (x) <= ROW && (y - 1) >= 1 && (y - 1) <= COL&&Show[x][y - 1] == '*')
			opeanMine(Mine, Show, x, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y - 1) >= 1 && (y - 1) <= COL&&Show[x + 1][y - 1] == '*')
			opeanMine(Mine, Show, x + 1, y - 1);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y) >= 1 && (y) <= COL&&Show[x + 1][y] == '*')
			opeanMine(Mine, Show, x + 1, y);
		if ((x + 1) >= 1 && (x + 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL&&Show[x + 1][y + 1] == '*')
			opeanMine(Mine, Show, x + 1, y + 1);
		if ((x) >= 1 && (x) <= ROW && (y + 1) >= 1 && (y + 1) <= COL&&Show[x][y + 1] == '*')
			opeanMine(Mine, Show, x, y + 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y + 1) >= 1 && (y + 1) <= COL&&Show[x - 1][y + 1] == '*')
			opeanMine(Mine, Show, x - 1, y + 1);
		if ((x - 1) >= 1 && (x - 1) <= ROW && (y) >= 1 && (y) <= COL&&Show[x - 1][y] == '*')
			opeanMine(Mine, Show, x - 1, y);
	}
	else
	{
		Show[x][y] = GetMine(Mine, x, y) + '0';
	}
	return 0;
}
static int IsWin(char Mine[ROWS][COLS], int row, int col)        //�ж�Ӯ
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (Mine[i][j] == '*')
				count++;
		}
	}
	return count;
}
int FindMine(char Mine[ROWS][COLS], char Show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 1;
	while (MINENUM != IsWin(Show, row, col)) 
	{
		int count = 0;
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("�Ƿ����꣬");
		}
		else if (Show[x][y] != '*')
		{
			printf("�õ����ѱ����٣�");
		}
		else if (Mine[x][y] == '1' && flag == 1)
		{
			moveMine(Mine, x, y);
			opeanMine(Mine, Show, x, y);
			system("cls");
			Print(Show, ROW, COL);
			flag = 0;
		}
		else if (Mine[x][y] == '1' && flag == 0)
		{
			printf("��Ϸ�������㱻ը����\n\n");
			Print(Mine, ROW, COL);
			return 0;
		}
		else if (Mine[x][y] == '0')
		{
			opeanMine(Mine, Show, x, y);
			system("cls");
			Print(Show, ROW, COL);
			flag = 0;
		}
	}
	printf("��ϲ�㣬ɨ�׳ɹ�\n");
	return 0;
}