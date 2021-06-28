#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>



//				斐波那契数列（循环）
int fibb(int a) {
	int left = 1;
	int rigth = 1;
	int sum = 1;
	
	while(a>2){
			sum = left + rigth;
			left = rigth;
			rigth = sum;
			a--;
		}
	return sum;
}

int main() {
	int a = 0;
	int fib = 0;
	scanf("%d",&a);
	fib = fibb(a);
	printf("%d",fib);
}