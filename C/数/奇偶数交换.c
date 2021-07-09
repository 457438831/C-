
#include <stdio.h>
#include <assert.h>

// 奇数偶数交换(奇数在前偶数在后)
void jioupaixu(int* arr,const int len)
{
	assert(arr&&len);
	//从左边找一个奇数
	//从右边找一个偶数
	//交换
	int* left = arr;//首元素指针
	int* rigth = &arr[len - 1];//尾元素指针
	int i = 0;
	while (left < rigth)
	{
		if (*left % 2)
		{
			left++;//如果结果为1即奇数  则不变 判断下一个元素
		}
		else
		{  //如果left为偶数则rigth开始查找一个奇数与他调换
			if (*rigth % 2)
			{
				int tmp = *left;
				*left = *rigth;
				*rigth = tmp;
			}
			else
			{
				rigth--;//如果结果为0即偶数  则不变 判断下一个元素
			}
		}
	}
}

void print(const int* arr,const int sz)
{
	assert(arr&&sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	jioupaixu(arr,sz);
	print(arr,sz);
	return 0;
}