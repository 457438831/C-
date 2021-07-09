#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>





//				函数指针使用场景
int Sum(int x, int y) { return x + y; } //加
int Sub(int x, int y) { return x - y; } //减
int Mul(int x, int y) { return x * y; } //乘
int Div(int x, int y) { return x / y; } //除
int Bor(int x, int y) { return x ^ y; } //异或

void menu()
{
	printf("############################\n");
	printf("######1,Sum  2,Sub   3,Mul##\n");
	printf("######4,Div  5,Bor  0,exit##\n");
	printf("############################\n");
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int (*parr[])(int, int) = {0,Sum,Sub,Mul,Div,Bor};   //函数指针数组   即一个数组装着指向函数的指针
	do
	{
		menu();  
		printf("请选择项目：");
		scanf("%d",&input);
		if (input>=1&&input<=5)
		{
			printf("请输入操作数：");
			scanf("%d%d", &x, &y);
			printf("%d\n", parr[input](x, y));   //利用数组中的指针调用函数
		}
		else if (input = 0) {
			printf("exit");
			break;
		}
		else {
			printf("input worring");
			break;
		}
		
	} while (input);
	return 0;
}