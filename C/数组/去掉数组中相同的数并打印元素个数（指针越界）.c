

#include <stdio.h>
#include <assert.h>
//			去掉数组中相同的数并打印元素个数（指针越界）
int dels(int* arr, int size)
{
	assert(arr&&size);
	int left = 0;			//初始化左比较元素的下标
	int right = 1;			//初始化右比较元素的下标
	int num = 0;			//初始化不同元素长度
	while (right < size)
	{
		if (arr[left] != arr[right])
		{
			arr[num] = arr[left];
			left++;
			right++;
			num++;
		}
		else
		{
			left++;
			right++;
		}
	}
	arr[num] = arr[left];//如果相同则在循环内未赋值 right越界 left指向最后一个元素    若不同在循环内赋值 num++ right越界 left指向最后一个元素
	num++;
	return num;//因为num始终比有元素的下标多1即 看为元素个数
}

//遍历数组
void print(const int arr[],const int num)
{
	assert(arr);
	for (int i = 0; i < num; i++)
	{
		printf("%d",arr[i]);
	}
}

int main()
{
	int arr[] = { 1,2,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = dels(arr,size);       //删除重复元素并计算元素个数
	printf("数组中有:%d个不相同的元素\n",num);
	print(arr,num);                 //遍历数组
	return 0;
}