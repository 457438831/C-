
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//			��һ������N�η����ݹ飩
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
	printf("%d��%d�η��ǣ�%lf",input,cf,jieguo);
	return 0;
}