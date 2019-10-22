#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

int Mystrlen1(const char* src)
{
	assert(src != NULL);
	int count = 0;
	while(*src)
	{
		src++;
		count++;
	}
	return count;
}//指针移位到'\0'，计算移位的次数

int Mystrlen2(const char* src)
{
	assert(src != NULL);
	if (*src=='\0')
	{
		return 0;
	}
	else
	{
		return 1 + Mystrlen2(src + 1);
	}
}//递归实现

int Mystrlen3(const char* src)
{
	assert(src != NULL);
	const char* end = src;
	while (*end)
	{
		++end;
	}
	return end - src;
}//尾-首

int main()
{
	char *a = "hello";
	printf("%d\n", strlen(a));
	printf("%d\n", Mystrlen1(a));
	printf("%d\n", Mystrlen2(a));
	printf("%d\n", Mystrlen3(a));
	return 0;
}