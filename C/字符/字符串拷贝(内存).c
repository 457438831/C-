
#include <stdio.h>
#include <assert.h>




//		 实现内存拷贝

/*在两个不同数组 数据拷贝  （粘贴目标，拷贝目标，拷贝长度）*/
void my_memcpy(void* dest, const void* rst, size_t len)
{
	assert(dest && rst);
	while (len--)
	{
		*(char*)dest = *(char*)rst;
		++(char*)dest;
		++(char*)rst;
	}
}

//		实现在一个数组中拷贝数据

/*在同一个数组 数据拷贝 （粘贴目标，拷贝目标，拷贝长度）*/
void my_memmove(void* dest, const void* rst, size_t len)
{
	assert(dest && rst);
	if (dest < rst)				//目的地在源头的前面  从第一个开始拷贝
	{
		my_memcpy(dest, rst, len);
	}
	else						//  其他情况都从后往前拷贝
	{
		char* in = ((char*)dest) + len - 1;
		char* go = ((char*)rst) + len - 1;

		while (len--)
		{
			*in = *go;
			go--;
			in--;
		}
	}
}

//两个数组进行的整数拷贝
void intpt()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));	//将arr1数组的内容 拷贝到arr2数组中
	for (size_t i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		printf("%d ", arr2[i]);
	}
}

// 两个数组进行的字符串拷贝
void copystr()
{
	char str1[] = "白日依山尽";
	char str2[11] = { 0 };
	my_memcpy(str2, str1, sizeof(str1));  //将str1字符串中的内容拷贝到str2中
	printf("%s ", str2);
}

// 在一个数组内进行的拷贝
void copyone()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 16);	//从arr开始拷贝(即起始位置)  到arr[2]的位置 长度为16字节(即4个int)
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	intpt();						//整数数组拷贝
	printf("\n");
	copystr();						//字符串数组拷贝
	printf("\n");
	copyone();						//拷贝数据  在同一数组内
	return 0;
}