
#include <stdio.h>
#include <math.h>


//		求0--10W之内的水仙花数     水仙花数=每位数的位数次方的和，等于它本身
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//  求这个数是几位数    
		int num = 1;
		int tmp = i;
		while (tmp/=10)//除到商为零  即n为位数
		{
			num++;
		}
		//		求每位数的平方之和
		int a = i;
		int sum = 0;
		int j = 0;
		for ( j = 0; j < num; j++)
		{
			sum += pow(a % 10, num);//pow求一个数的次方
			a = a / 10;
		}
		//			判断和是否与本身相等
		if (sum == i)
		{
			printf("%d \n",i);
		}
	}
	return 0;
}
