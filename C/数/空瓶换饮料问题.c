#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>




//				空瓶换饮料问题
int main()
{
	int jiage = 1;
	int money = 0;
	int drink = 0;
	int kongping = 0;
	scanf("%d",&money);
	drink = money / jiage;  //总金额除以单价得瓶数 即空瓶数
	kongping = drink;
	while (kongping >= 2)
	{
		drink += kongping / 2;//空瓶数除以2即再次兑换到的瓶数  +之前喝的瓶数即总瓶数
		kongping = kongping / 2 + kongping % 2;//空瓶数量等于兑换到的饮料数量 + 剩下的空瓶
	}
	printf("%d ",drink);
	return 0;
}