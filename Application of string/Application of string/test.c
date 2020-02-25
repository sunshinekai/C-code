//1.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

int Judge_string(char *s1, char *s2)
{
	assert((s1 != NULL) && (s2 != NULL));
	if (strlen(s1) != strlen(s2))
		return 0;

	strncat(s1, s1, strlen(s1));

	if (strstr(s1, s2) == NULL)
		return 0;

	else
		return 1;
}

int main()
{
	char s1[20] = "AABCD";//数组必须要足够大
	char s2[20] = "BCDAA";
	//char s1[20] = "abcd";
	//char s2[] = "ABCD";//
	int ret = Judge_string(s1, s2);
	if (ret == 0)
	{
		printf("0\n");
	}
	else
	{
		printf("1\n");
	}
	return 0;
}


#if 0
//2.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA 
//ABCD左旋两个字符得到CDAB
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

void Levo(char *pstr, int SZ, int key)
{
	assert(pstr != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < key; i++)
	{
		char tmp = pstr[0];

		for (j = 0; j < SZ - 1; j++)
		{
			pstr[j] = pstr[j + 1];
		}
		pstr[SZ - 1] = tmp;
	}

}

int main()
{
	char str[] = "ABCD";
	int key = 0;
	int SZ = sizeof(str) / sizeof(str[0]) - 1;
	printf("请输入你要旋转字符的个数:>");
	scanf("%d", &key);
	Levo(str, SZ, key);
	printf("%s", str);
	return 0;
}
#endif