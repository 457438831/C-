#include <stdio.h>

//三个数的大到小排列
int main() {
	int a;
	int b;
	int c;
	int d;
	printf("请输入三个整数：");
	scanf("%d%d%d", &a, &b, &c);
	if (a < b) {
		d = a;
		a = b;
		b = d;
	}
	if (a < c) {
		d = a;
		a = c;
		c = d;
	}
	if (b < c) {
		d = b;
		b = c;
		c = d;
	}
	printf("从大到小排列为：%d,%d,%d", a, b, c);
	return 0;
}