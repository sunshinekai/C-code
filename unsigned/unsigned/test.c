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
/*������Ϊ��>��,��4������Ϊsizeof(i)����Ϊunsigned int,
int���޷��űȽ�ʱ����������������-1Ϊȫ1��
��Ϊ32λ����������Խ��Ϊ����*/