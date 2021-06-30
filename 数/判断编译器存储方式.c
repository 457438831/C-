
#include <stdio.h>

//			判断编译器是大端还是小端存储
//大端即 00 00 00 01 小端即 01 00 00 00 
int check_sys() 
{
	int i = 1;
	return *(char*)&i;
}

int main()
{
	int i = 0;
	i = check_sys();
	if (i == 0)
	{
		printf("该编译器是大端存储！");
	}
	else if (i == 1) 
	{
		printf("该编译器是小端存储");
	}
	return 0;
}
