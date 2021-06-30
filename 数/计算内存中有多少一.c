
#include <stdio.h>

extern void sum1();
extern void sum2();
int main()
{
	sum1();//方法一
	sum2();//方法二
}

//				计算有多少个一
void sum1() {

	int num = 5;
	int i = 0;
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);//一个数与上自身减一即内存中会消失一个一
	}
	printf("二进制中1的个数 %d\n",count);

	return 0;
}

//			求有多少个一（指针位移  与）
void sum2(){

	int a = 5;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (1 == ((a >> i) & 1) ) { //移位操作符    按位与    
			count++;//一个数与上1为1则此位为1，相反为零   
		}
	}
	printf("二进制中1的个数 %d", count);
	return 0;
}