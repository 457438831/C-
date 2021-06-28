#include <stdio.h>


//			异或交换变量值（不使用新变量）
int main() {

	int a = 5;
	int b = 2;

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a:%d\nb:%d", a, b);
}