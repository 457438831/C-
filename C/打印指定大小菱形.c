#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//			打印菱形
int main()
{
	//1,打印上半部分
	int i = 0;
	int line = 0;
	scanf("%d",&line);
	for (i = 0; i < line; i++)
	{
		//打印空格
		int b = 0;
		for (b = 0; b < line - 1 - i; b++)   //空格是逐渐递减1  且最后一行没有空格  所以行数-1
		{
			printf(" ");
		}
		//打印*
		for ( b = 0; b < 2*i+1; b++)		 //第一行一个第二行3个 即行数*2-1等于下一行*数量
		{
			printf("*");
		}
		printf("\n"); //打印完一行换行
	}
	//2，打印下半部分
	for ( i = 0; i < line-1; i++)			 //因为第一行是满*状态所以少打印一行
	{
		//打印空格
		int b = 0;
		for (b = 0; b < i + 1; b++)          //空格是逐渐递增的即随i增大而增大
		{
			printf(" ");
		}
		//打印*
		for ( b = 0; b < 2*(line -1 -i)-1; b++)  //*是随行数递增减小的，数量为2*line-1，且下半部分行数少一 即为2*（line-1）-1，又因行数递减,则*数量为2*(line-1-i)-1 
		{
			printf("*");
		}
		printf("\n");  //打印完一行换行
	}
	return 0;
}