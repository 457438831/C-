
//			求整数二进制有多少一

#include <stdio.h>


//		指针位移算法
void count_bit_three(int a)
{
	int i = 0;
	int count = 0;
	for ( i = 0; i < 32; i++)
	{
		if (1 == ((a >> i) & 1)) {
			count++;
		}
	}
	printf("%d\n",count);
}

//		与差算法
void count_bit_two(int a)
{
	int count = 0;
	unsigned int b = a;
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	printf("%d\n",count);
}

//   求余算法
void  count_bit(int a)
{
	int i = 0;
	int count = 0;
	unsigned int b = a;
	for (i = 0; i < 32; i++)
	{
		if (1 == b % 2) {
			count++;
		}
		b = b / 2;
	}
	printf("%d\n",count);
}
int main()
{
	int a = -1;
	count_bit(a);
	count_bit_two(a);
	count_bit_three(a);
	return 0;
}