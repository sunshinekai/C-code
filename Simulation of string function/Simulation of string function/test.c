// 1.ģ��ʵ��strcpy
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* str)
{
	assert(dest && str);
	char* add = dest;
	while (*dest++ = *str++)
		NULL;

	return add;
}   // �ַ����Ŀ���

//int main()
//{
//	char dest[20];
//	printf("%s\n", strcpy(dest, "hello world"));
//	printf("%s\n", my_strcpy(dest, "hello wor1d"));
//	return 0;
//}


// 2.ģ��ʵ��strcat
char* my_strcat(char* dest, const char* str)
{
	assert(dest && str);
	char* add = dest;
	while (*dest++);

	while (*dest++ = *str++);

	return add;
}   // �ַ�����׷��

//int main()
//{
//	char dest[20] = { "hello " };
//	printf("%s\n", strcat(dest, "world"));
//	printf("%s\n", my_strcat(dest, "world"));
//	return 0;
//}


// 3.ģ��ʵ��strstr
char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);  
	assert(str2);
	char *cp = (char*)str1;  
	char *substr = (char *)str2;  
	char *s1 = NULL;
	if (*str2 == '\0')
		return NULL;

	while (*cp)
	{
		s1 = cp;
		substr = (char*)str2;

		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}

		if (*substr == '\0')
			return cp;

		cp++;
	}

	return NULL;
}   //�ַ�����ƥ��(�����ƥ��֮����ַ���)

//int main()
//{
//	char str[] = "abcdefghi";
//	printf("%s\n", strstr(str, "cdef"));
//	printf("%s\n", my_strstr(str, "cdef"));
//	return 0;
//}


// 4.ģ��ʵ��strchr
char *  my_strchr(const char * string, int ch)
{
	while (*string && *string != (char)ch)
		string++;

	if (*string == (char)ch)
		return((char *)string);

	return(NULL);
}   // �����ַ���s���״γ���ch�ַ���λ��

//int main()
//{
//	char string[20];
//	char *ptr, c = 'r';
//	strcpy(string, "This is a string");
//	ptr = my_strchr(string, c);
//
//	if (ptr)
//		printf("The character %cis at position:%s\n", c, ptr);
//
//	else
//		printf("The character was not found\n");
//
//	return 0;
//}


// 5.ģ��ʵ��strcmp
int my_strcmp(const char * src, const char * dst)
{
	int ret = 0;
	assert(src);
	assert(dst);
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
	{
		++src;
		++dst;
	}

	if (ret < 0)
		ret = -1;

	else if (ret > 0)
		ret = 1;

	return ret;
}	// �ַ����ıȽ�

//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "abcdef";
//	printf("%d\n", strcmp(str1, str2));
//	printf("%d\n", my_strcmp(str1, str2));
//	return 0;
//}


// 6.ģ��ʵ��memcpy
void * my_memcpy(void * dst, const void * src, size_t count)
{
	void * ret = dst;
	assert(dst);
	assert(src);

	while (count--)
	{
		*(char *)dst = *(char *)src;
		dst = (char *)dst + 1;
		src = (char *)src + 1;
	}

	return(ret);
}   // ��Դ�ڴ��ַ����ʼλ�ÿ�ʼ�������ɸ��ֽڵ�Ŀ���ڴ��ַ

//int main()
//{
//	char str1[20] = { 0 };
//	char str2[] = "abcdef";
//	int len = sizeof(str2) / sizeof(str2[0]);
//	printf("%s\n", memcpy(str1, str2, len));
//	printf("%s\n", my_memcpy(str1, str2, len));
//	return 0;
//}


// 7.ģ��ʵ��memmove
void * my_memmove(void * dst, const void * src, size_t count)
{
	void * ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}

	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;

		while (count--) 
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst - 1;
			src = (char *)src - 1;
		}
	}

	return(ret);
}   // �����ֽ�

/* ��Ŀ�������Դ�������ص��Ļ����ܹ���֤Դ���ڱ�����֮ǰ��
�ص�������ֽڿ�����Ŀ�������У������ƺ�Դ���ݻᱻ���� */

//int main()
//{
//	char str1[20] = "abcd";
//	char str2[] = "abcdef";
//	printf("%s\n", memmove(str1, str2, 2));
//	printf("%s\n", my_memmove(str1, str2, 2));
//	return 0;
//}


//8.ģ��ʵ��strncpy
char * my_strncpy(char * dest, const char * source, size_t count)
{
	char *start = dest;

	while (count && (*dest++ = *source++))
		count--;

	if (count)
	while (--count)
		*dest++ = '\0';

	return start;
}	// ��ָ�����ȵ��ַ������Ƶ��ַ�������


//int main()
//{
//	char *s1 = "I love you" ;
//	char s2[20] = { 0 };
//	printf("%s\n", strncpy(s2, s1, 8));
//	printf("%s\n", my_strncpy(s2, s1, 8));
//	return 0;
//}


// 9.ģ��ʵ��strncat
char *  my_strncat(char * front, const char * back, size_t count)
{
	char *start = front;

	while (*front++)
		;
	front--;

	while (count--)
	if (!(*front++ = *back++))
		return(start);

	*front = '\0';
	return(start);
}	// ���ַ����Ľ�β׷��n���ַ�

//int main()
//{
//	char s1[20] = { "Hello World " };
//	char s2[20] = { "and me" };
//	char *s3 = strncat(s1, s2, 3);
//	char *s4 = my_strncat(s1, s2, 3);
//	printf("%s\n", s3);
//	printf("%s\n", s4);
//	return 0;
//}


// 10.ģ��ʵ��strncmp
int my_strncmp(const char *first, const char *last, size_t  count)
{
	size_t x = 0;

	if (!count)
	{
		return 0;
	}

	if (count >= 4)
	{
		for (; x < count - 4; x += 4)
		{
			first += 4;
			last += 4;

			if (*(first - 4) == 0 || *(first - 4) != *(last - 4))
			{
				return(*(unsigned char *)(first - 4) - *(unsigned char *)(last - 4));
			}

			if (*(first - 3) == 0 || *(first - 3) != *(last - 3))
			{
				return(*(unsigned char *)(first - 3) - *(unsigned char *)(last - 3));
			}

			if (*(first - 2) == 0 || *(first - 2) != *(last - 2))
			{
				return(*(unsigned char *)(first - 2) - *(unsigned char *)(last - 2));
			}

			if (*(first - 1) == 0 || *(first - 1) != *(last - 1))
			{
				return(*(unsigned char *)(first - 1) - *(unsigned char *)(last - 1));
			}
		}
	}

	for (; x < count; x++)
	{
		if (*first == 0 || *first != *last)
		{
			return(*(unsigned char *)first - *(unsigned char *)last);
		}

		first += 1;
		last += 1;
	}

	return 0;
}	// �� first �� last ���бȽϣ����Ƚ�ǰ count ���ֽ�


int main()
{
	char s1[20] = { "abcde" };
	char s2[20] = { "abdde" };
	int len1 = strncmp(s1, s2, 3);
	int len2 = my_strncmp(s1, s2, 3);
	printf("%d\n", len1);
	printf("%d\n", len2);
	return 0;
}