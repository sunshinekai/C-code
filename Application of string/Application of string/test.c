//1.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

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
	char s1[20] = "AABCD";//�������Ҫ�㹻��
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
//2.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA 
//ABCD���������ַ��õ�CDAB
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
	printf("��������Ҫ��ת�ַ��ĸ���:>");
	scanf("%d", &key);
	Levo(str, SZ, key);
	printf("%s", str);
	return 0;
}
#endif