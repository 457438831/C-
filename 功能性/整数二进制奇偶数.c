#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//				整数奇/偶数位打印
void print(int a)
{
	int i = 0;
	//奇数位
	printf("奇数位\n");
	for (i = 30; i >=0; i -= 2)
	{
		printf("%d ",( a >> i ) & 1 );
	}
	//偶数位
	printf("\n偶数位\n");
	for (i = 31; i >= 0 ; i -= 2)
	{
		printf("%d ",(a >> i ) & 1 );
	}
}

int main()
{
	int a = 0;
	scanf("%d",&a);
	print(a);
	return 0;
}
