#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>




//			数字每位数之和（递归）
int Digitsum(unsigned int input)
{
	int a = 0;
	int b = 0;
	a = input % 10;
	b = input / 10;
	if (b > 9) {
		return a + Digitsum(b);
	}
	else {
		return a + b;
	}
}

int main()
{
	int input = 0;
	int sum = 0;
	scanf("%d",&input);
	sum = Digitsum(input);
	printf("%d", sum);
	return 0;
}