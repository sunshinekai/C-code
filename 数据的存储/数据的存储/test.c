#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h> 
#include<string.h>
int main()
{
		int n = 9;  
		//00000000 00000000 0000000 00001001 
		float *pFloat = (float *)&n;  
		printf("n的值为：%d\n", n);  //9
		printf("*pFloat的值为：%f\n", *pFloat);//0.000000
		//以浮点类型视角去读取数据
		//0 00000000 00000000000000000001001
		*pFloat = 9.0;
		//1.001*2E3
		//0 10000010 00100000000000000000000
		printf("num的值为：%d\n", n);
		//以整型视角去读取数据
		//1091567616
		printf("*pFloat的值为：%f\n", *pFloat);  //9.000000
		return 0;
}
#if 0
unsigned char i = 0;
int main() 
{    
	for(i = 0;i<=255;i++)     
	{        
		printf("hello world\n");    
	}    
	return 0; 
}
int main()
{
	char a[1000];
	int i;
	for (i = 0; i<1000; i++)     
	{
		a[i] = -1 - i; 
	}    
	printf("%d", strlen(a));    
	return 0; 
}
int main()
{
	unsigned int i; 
	for (i = 9; i >= 0; i--) 
	{ 
		printf("%u\n", i); 
	}
	return 0;
}
int main()
{
	int i = -20; 
	unsigned  int  j = 10; 
	printf("%d\n", i + j);
	return 0;
}
int main()
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d", a, b, c);
	return 0;
}
#endif