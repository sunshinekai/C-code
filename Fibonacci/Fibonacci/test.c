#include<stdio.h>
#include<time.h>
#define N 40
int Fibonacci1(int n)
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

int Fibonacci2(int n)
{
	if (n < 2)
		return n;

	return Fibonacci2(n - 1) + Fibonacci2(n - 2);
}

int Fibonacci3(int n)
{
	return n < 2 ? n : Fibonacci3(n - 1) + Fibonacci3(n - 2);
}

int FibonacciNonR(int n)
{
	if (n == 0)
		return 0;

	int x = 1;
	int y = 1;
	int ret = x;

	while (n > 2)
	{
		ret = x + y;
		x = y;
		y = ret;
		n--;
	}
	return ret;
}

void TimeTest()
{
	int begin1 = clock();
	Fibonacci1(N);
	int end1 = clock();

	int begin2 = clock();
	Fibonacci2(N);
	int end2 = clock();

	int begin3 = clock();
	Fibonacci3(N);
	int end3 = clock();

	int begin4 = clock();
	FibonacciNonR(N);
	int end4 = clock();

	printf("Fibonacci1:%d\n", end1 - begin1);
	printf("Fibonacci2:%d\n", end2 - begin2);
	printf("Fibonacci3:%d\n", end3 - begin3);
	printf("Fibonacci4:%d\n", end4 - begin4);
}

void FibonacciTest()
{
	printf("Fibonacci1:%d\n", Fibonacci1(N));
	printf("Fibonacci2:%d\n", Fibonacci2(N));
	printf("Fibonacci3:%d\n", Fibonacci3(N));
	printf("FibonacciNonR:%d\n", FibonacciNonR(N));
}

int main()
{
	TimeTest();
	FibonacciTest();
	return 0;
}