#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
float Average1(float a, float b)
{
	return ((a + b) / 2);
}//ֱ�Ӽ���
//�ŵ㣺���ȸߣ����㷽�� ȱ�㣺�������ܻ�������

float Average2(float a, float b)
{
	return (a + (b - a) / 2);
}//ȡ������Ĳ��ֲ����ٵ���
//�ŵ㣺���ȸߣ�ȱ�㣺�����ٶ���

int Average3(int a, int b)
{
	return (((a^b)>>1) + (a&b));
}//λ����
//�ŵ㣺�� ȱ�㣺ֻ��������

int main()
{
	float a = 0;
	float b = 0;
	printf("Please input two number:>");
	scanf("%f %f", &a, &b);
	printf("The average is:>\n");
	printf("%.2f\n", Average1(a, b));
	printf("%.2f\n", Average2(a, b));
	printf("%d\n", Average3((int)a, (int)b));
	return 0;
}