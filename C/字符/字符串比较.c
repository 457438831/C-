
#include <stdio.h>
#include <assert.h>


//		strcmp  字符串大小判断(比较的是字符的ASCLL码值)
int my_strcmp(const char* arr1,const char* arr2)
{//
	assert(arr1 && arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')//arr1大返回正数  相等返回0    arr1小返回负数
			return 0;
		arr1++;
		arr2++;
	}
	return *arr1 - *arr2;
}

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcde";
	int ret = my_strcmp(arr1,arr2);
	if (ret > 0)
	{
		printf("arr1 > arr2");
	}
	else if (ret == 0)
	{
		printf("arr1 = arr2");
	}
	else {
		printf("arr1 < arr2");
	}
	return 0;
}