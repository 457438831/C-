#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//					쳲��������� (�ݹ�)
//1 1 2 3 5 8 13... ��ǰ����֮�͵�����һ����

int fib(int a) {
	if (a <= 2) {
		return 1;
	}
	else {
		return fib(a - 1) + fib(a - 2);
	}
}

int main() {
	int a = 0;
	int b = 0;
	scanf("%d",&a);
	b = fib(a);
	printf("%d",b);
	return 0;
}
