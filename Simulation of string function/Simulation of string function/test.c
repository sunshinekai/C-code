// 1.模拟实现strcpy
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
}   // 字符串的拷贝

//int main()
//{
//	char dest[20];
//	printf("%s\n", strcpy(dest, "hello world"));
//	printf("%s\n", my_strcpy(dest, "hello wor1d"));
//	return 0;
//}


// 2.模拟实现strcat
char* my_strcat(char* dest, const char* str)
{
	assert(dest && str);
	char* add = dest;
	while (*dest++);

	while (*dest++ = *str++);

	return add;
}   // 字符串的追加

//int main()
//{
//	char dest[20] = { "hello " };
//	printf("%s\n", strcat(dest, "world"));
//	printf("%s\n", my_strcat(dest, "world"));
//	return 0;
//}


// 3.模拟实现strstr
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
}   //字符串的匹配(并输出匹配之后的字符串)

//int main()
//{
//	char str[] = "abcdefghi";
//	printf("%s\n", strstr(str, "cdef"));
//	printf("%s\n", my_strstr(str, "cdef"));
//	return 0;
//}


// 4.模拟实现strchr
char *  my_strchr(const char * string, int ch)
{
	while (*string && *string != (char)ch)
		string++;

	if (*string == (char)ch)
		return((char *)string);

	return(NULL);
}   // 查找字符串s中首次出现ch字符的位置

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


// 5.模拟实现strcmp
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
}	// 字符串的比较

//int main()
//{
//	char str1[] = "abcd";
//	char str2[] = "abcdef";
//	printf("%d\n", strcmp(str1, str2));
//	printf("%d\n", my_strcmp(str1, str2));
//	return 0;
//}


// 6.模拟实现memcpy
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
}   // 从源内存地址的起始位置开始拷贝若干个字节到目标内存地址

//int main()
//{
//	char str1[20] = { 0 };
//	char str2[] = "abcdef";
//	int len = sizeof(str2) / sizeof(str2[0]);
//	printf("%s\n", memcpy(str1, str2, len));
//	printf("%s\n", my_memcpy(str1, str2, len));
//	return 0;
//}


// 7.模拟实现memmove
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
}   // 拷贝字节

/* 若目标区域和源区域有重叠的话，能够保证源串在被覆盖之前将
重叠区域的字节拷贝到目标区域中，但复制后源内容会被更改 */

//int main()
//{
//	char str1[20] = "abcd";
//	char str2[] = "abcdef";
//	printf("%s\n", memmove(str1, str2, 2));
//	printf("%s\n", my_memmove(str1, str2, 2));
//	return 0;
//}


//8.模拟实现strncpy
char * my_strncpy(char * dest, const char * source, size_t count)
{
	char *start = dest;

	while (count && (*dest++ = *source++))
		count--;

	if (count)
	while (--count)
		*dest++ = '\0';

	return start;
}	// 将指定长度的字符串复制到字符数组中


//int main()
//{
//	char *s1 = "I love you" ;
//	char s2[20] = { 0 };
//	printf("%s\n", strncpy(s2, s1, 8));
//	printf("%s\n", my_strncpy(s2, s1, 8));
//	return 0;
//}


// 9.模拟实现strncat
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
}	// 在字符串的结尾追加n个字符

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


// 10.模拟实现strncmp
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
}	// 把 first 和 last 进行比较，最多比较前 count 个字节


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