#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Menu()
{
	printf("****************************\n");
	printf("*****��ӭ����ɨ��С��Ϸ*****\n");
	printf("***********1.paly***********\n");
	printf("***********0.exit***********\n");
	printf("****************************\n");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	c_mine(mine, ROWS, COLS);      //��ʼ������
	SetMine(mine, ROW, COL);       //������
	c_show(show, ROWS, COLS);      //��ʼ��show
	//Print(mine, ROW, COL);       //��ӡ����
	Print(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		Menu();
		printf("��������Ĳ���:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}