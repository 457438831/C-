#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


//                 区间素数及数量
//		素数：只能被1和本身整除的数
int main() {
	int i = 0;
	int count = 0;
	int left= 0;
	int rigth = 0;
	scanf("%d%d",&left,&rigth);
	for (i = left; i <=rigth; i++)
	{
		int b = 0;
		for (b = 2; b <= sqrt(i); b++)
		{
			if (i % b==0) {
				break;
			}
		}
		if (b > sqrt(i)) {
			printf("%d ", i);
			count++;
		}
	}
	printf("素数有：%d 个",count);
	return 0;
}