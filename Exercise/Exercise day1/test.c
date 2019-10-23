#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
float Average1(float a, float b)
{
	return ((a + b) / 2);
}//直接计算
//优点：精度高；计算方便 缺点：慢，可能会造成溢出

float Average2(float a, float b)
{
	return (a + (b - a) / 2);
}//取多出来的部分补到少的上
//优点：精度高；缺点：计算速度慢

int Average3(int a, int b)
{
	return (((a^b)>>1) + (a&b));
}//位运算
//优点：快 缺点：只能求整型

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