#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>





//				����ָ��ʹ�ó���
int Sum(int x, int y) { return x + y; } //��
int Sub(int x, int y) { return x - y; } //��
int Mul(int x, int y) { return x * y; } //��
int Div(int x, int y) { return x / y; } //��
int Bor(int x, int y) { return x ^ y; } //���

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
	int (*parr[])(int, int) = {0,Sum,Sub,Mul,Div,Bor};   //����ָ������   ��һ������װ��ָ������ָ��
	do
	{
		menu();  
		printf("��ѡ����Ŀ��");
		scanf("%d",&input);
		if (input>=1&&input<=5)
		{
			printf("�������������");
			scanf("%d%d", &x, &y);
			printf("%d\n", parr[input](x, y));   //���������е�ָ����ú���
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