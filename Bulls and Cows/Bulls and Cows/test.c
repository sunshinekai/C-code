#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define M 50    // �����޸����ַ�Χ
#define N 5    // �����޸Ļ������

void Menu()
{
	printf("**************************\n");
	printf("****��ӭ������������Ϸ****\n");
	printf("**********0.exit**********\n");
	printf("**********1.play**********\n");
	printf("**************************\n");
	printf("==========================\n");
}

void game()
{
	int num = rand() % M + 1;
	int n = 0, i = 0;
	printf("������һ��1-%d�����֣����ܹ���%d�λ���:\n",M,N);
	scanf("%d", &n);

	while (i < N)
	{
		if (n == num)
		{
			printf("��ϲ��¶���!\n\n");
			break;
		}

		if (i == N - 1)
		{
			printf("���ź���û�в¶�,��Ϸ����.\n");
			printf("��ȷ��Ϊ:%d\n", num);
			break;
		}

		if (n > num)
		{
			printf("����!\n");
			printf("����������:\n");
		}

		if (n < num)
		{
			printf("С��!\n");
			printf("����������:\n");
		}

		if (i == N - 2)
		{
			printf("�㻹�����һ�λ���!\n");
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
				printf("���벻�Ϸ�������������:\n");
				break;
		}
	} while (input);
	return 0;
}