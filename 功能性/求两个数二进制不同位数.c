
#include <stdio.h>

//			求两个数二进制不相同个数
int get_number(int a, int b)
{
	int c = 0;
	int count = 0;
	c = a ^ b;//先异或  相同为零不同为一   求出异或后有几个一即可
	while (c)
	{
		c = c & (c - 1); //与差法
		count++;
	}
	return count;
}

int main()
{
	int a = 5;
	int b = 10;
	int count = 0;
	count = get_number(a,b);
	printf("有：%d 位不一样",count);
	return 0;
}

