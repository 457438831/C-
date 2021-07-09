
#include <stdio.h>
#include <assert.h>



//				字符长度计算（最优函数设计）
int my_strlen(const char* arr)
{
	assert(arr != NULL);
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}


int main()
{
	char arr[] = {"hello world 0"};
	printf("%d",my_strlen(arr));
}