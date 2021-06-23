#include <stdio.h>

//			½×³Ë ¼°n*1*2*3...
int main() {
	int sum = 1;
	int i = 0;
	int a = 0;
	scanf("%d", &a);
	for (i = 1; i <= a; i++)
	{
		sum = sum * i;
	}
	printf("%d\n", sum);
	return 0;
}
