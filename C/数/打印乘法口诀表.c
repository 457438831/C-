#include <stdio.h>


//			乘法口诀表打印
int main() {
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for  (j = 1; j <= i; j++)
		{
			printf("%d * %d = %-2d ",j, i, j*i);//左对齐
		}
		printf("\n");
	}
	return 0;
}