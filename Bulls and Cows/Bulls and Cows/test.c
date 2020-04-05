#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define M 50    // 用于修改数字范围
#define N 5    // 用于修改机会次数

void Menu()
{
	printf("**************************\n");
	printf("****欢迎来到猜数字游戏****\n");
	printf("**********0.exit**********\n");
	printf("**********1.play**********\n");
	printf("**************************\n");
	printf("==========================\n");
}

void game()
{
	int num = rand() % M + 1;
	int n = 0, i = 0;
	printf("请输入一个1-%d的数字，你总共有%d次机会:\n",M,N);
	scanf("%d", &n);

	while (i < N)
	{
		if (n == num)
		{
			printf("恭喜你猜对了!\n\n");
			break;
		}

		if (i == N - 1)
		{
			printf("很遗憾你没有猜对,游戏结束.\n");
			printf("正确答案为:%d\n", num);
			break;
		}

		if (n > num)
		{
			printf("大了!\n");
			printf("请重新输入:\n");
		}

		if (n < num)
		{
			printf("小了!\n");
			printf("请重新输入:\n");
		}

		if (i == N - 2)
		{
			printf("你还有最后一次机会!\n");
		}

		i++;
		scanf("%d", &n);
	}
	Sleep(2500);
	system("CLS");
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
				printf("输入不合法！请重新输入:\n");
				break;
		}
	} while (input);
	return 0;
}