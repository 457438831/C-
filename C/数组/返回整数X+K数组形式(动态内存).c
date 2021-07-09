#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//   给定非负整数X数组形式，返回整数X+K数组形式(动态内存)


int Max_length(int k, const int size)  //计算最大长度
{
	assert(size);
	int count = 0;
	while (k)
	{
		k /= 10;
		count++;
	}
	if (size > count)
		return size;
	else
		return count;
}

int* add(int* arr, int k, int* size)
{
	assert(arr && size);
	int remainder = 0;//余数
	int quotient = 0;//商
	int Initsize = *size;
	*size = Max_length(k, *size) + 1;
	int* Newarr = (int*)calloc(*size, 4);//开辟最长整数+1的长度
	if (Newarr == NULL)
	{
		printf("内存开辟失败: %s", strerror(errno));
		return NULL;
	}
	else
	{
		int* init = Newarr;
		for (int i = 0; i < Initsize; i++)  //将原数据拷贝到新空间
		{
			Newarr[*size - 1 - i] = arr[Initsize - 1 - i];
		}
		arr = init;
		printf("内存开辟成功");
	}

	for (int i = 0; i < *size; i++)
	{
		remainder = k % 10;
		quotient = k / 10;
		int up = arr[*size - 1 - i] + remainder;//进数
		if (up >= 10)
		{
			arr[*size - 1 - i] = up % 10;  //如果余数加数组中的数大于10，将求余结果放到数组中 将商加到总商去
			quotient += up / 10;
		}
		else
		{
			arr[*size - 1 - i] = up;
		}
		if (quotient)				//如果商为零即跳出循环
		{
			k = quotient;
		}
		else
			return arr;
	}
	return NULL;
}

void print(int* arr, const int size)
{
	assert(arr && size);
	if (arr[0] == 0)
	{
		for (int i = 1; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	else {
		for (int i = 0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	free(arr);				//这里是最后使用动态空间的地方  所以在这里释放
	arr = NULL;
}

int main()
{
	int arr[] = { 9,9,9,9,9,9,9,9,9,9 };//思路：重点什么时候开辟空间 1 操作数之前 （就不用挪动数据）【直接创建一个比最大长度多一的数组】重点怎么求整数最大长度？除以十记录次数   2操作数据时 （需要挪动数据）
	int k = 1;
	int size = sizeof(arr) / sizeof(arr[0]);
	int* Arr = add(arr, k, &size);
	print(Arr, size);
	return 0;
}