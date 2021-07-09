#include <stdio.h>


int jiecheng(int a) {
	if (a <= 1) {
		return 1;
	}
	else {
		return a * jiecheng(a-1);
	}
}

int main() {
	int a = 0;
	int b = 0;
	scanf("%d",&a);
	b = jiecheng(a);
	printf("%d",b);
	return 0;
}