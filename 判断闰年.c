#include <stdio.h>


//				判断闰年及数量（优化代码）
int main() {
	int year = 0;
	int count = 0;
	for (year = 1000; year <=2000; year++)
	{
		//判断闰年的规则
		//1,能被4整除且不能被100整除
		//2,能被400整除
		if (( 0 == year % 4 && 0 != year % 100) || ( 0 == year % 400)) {
			printf("%d  ",year);
			count++;
		}
	}
	printf("闰年有：%d 个",count);
	return 0;
}


