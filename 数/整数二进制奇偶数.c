#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//				������/ż��λ��ӡ
void print(int a)
{
	int i = 0;
	//����λ
	printf("����λ\n");
	for (i = 30; i >=0; i -= 2)
	{
		printf("%d ",( a >> i ) & 1 );
	}
	//ż��λ
	printf("\nż��λ\n");
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
