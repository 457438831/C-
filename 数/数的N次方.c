
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//			求一个数的N次方（递归）
double cifang(int input, int cf)
{
	if (cf >= 1) {
		return input * cifang(input, cf - 1);
	}
	else if (cf == 0) {
		return 1; 
	}
	else if (cf < 0) {
		return (1.0 / cifang(input,-cf));
	}
}

int main()
{
	int input = 0;
	int cf = 0;
	double jieguo = 0;
	scanf("%d%d",&input,&cf);
	jieguo =  cifang(input,cf);
	printf("%d的%d次方是：%lf",input,cf,jieguo);
	return 0;
}