#include<stdio.h>
int i;
int main()
{
	i--;
	if (i > sizeof(i))
		printf(">\n");

	else
		printf("<\n");

	printf("%d\n", sizeof(i));
	return 0;
}
/*输出结果为“>”,“4”，因为sizeof(i)类型为unsigned int,
int与无符号比较时，发生类型提升，-1为全1，
即为32位最大数。所以结果为大于*/