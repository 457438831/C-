#include <stdio.h>
#include <assert.h>



//realization of string length   字符串长度实现
//recursive method   递归方法

int my_strlen(const char* arr)
{
	assert(arr);
	if (*arr)//因为字符串结尾默认存储'\0'即ASCLL码值为0  不为零则表示有长度
	{
		return 1 + my_strlen(arr + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "abcd";
	printf("%d", my_strlen(arr));
	return 0;
}