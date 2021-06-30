
#include <stdio.h>
#include <assert.h>
#include <string.h>

//				字符串拷贝（最优函数设计）
char* my_copy(char* goal,const char* move)
{
	if (strlen(goal) >= strlen(move))
	{
		char* a = goal;
		assert(goal && move);
		//先赋值再加加，‘/0’值为0即假
		while (*goal++ = *move++) {
			;
		}
		return a;
	}
	return NULL;
}

int main()
{
	char arr[] = {"######################"};
	char arr2[] = {"白日依山尽，黄河入海流，欲穷千里目，更上一层楼"};
	if (my_copy(arr, arr2))
	{
		printf("%s", my_copy(arr, arr2));
	}
	else
	{
		printf("目标数组小于当前数组");
	}
	
	return 0;
}