
#include <stdio.h>
#include <assert.h>


//     去掉数组中相同的数并打印元素个数（指针不越界）
//	思路：创建1，2，3个指针，利用12指针进行两两比较，3记录最大数组下标防止越界，将不同的元素重新放到数组中
//  修改了原数组   且并未删除其他重复元素
int dels(int* arr,const int size)
{
	assert(arr);
	int* left = arr;                //比较指针左
	int* right = arr + 1;           //比较指针右
	int* end = arr + size - 1;      //数组结束位置
	int count = 0;                  //计数器

	for (int i = 0; i < size-1; i++)//因为是两两比较所以只需要比较size-1次
	{
		if (*left == *right)        //如果两个比较数相等即比较指针向后移动一位
		{
			if (right != end)       //判断比较指针右是否到达数组边界    防止越界访问
			{
				right++;
				left++;
			}
		}
		else                        //如果不相等就将比较指针左的值给arr
		{
			*arr = *left;
			arr++;
			count++;
			if (right != end)       //判断比较指针右是否到达素组边解    防止越界访问
			{
				right++;
				left++;
			}
		}
	}
	*arr = *right;                  //如果最后两位相同 则在循环内没有取值，在此将left或right赋值给不重复指针
	count++;                        //如果最后两位不同，则在循环内已经将left值赋给不重复指针，此时只需要将right值赋给不重复指针即可
	return count;
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
	int arr[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = dels(arr,size);       //删除重复元素并计算元素个数
	printf("数组中有:%d个不相同的元素\n",num);
	print(arr,num);                 //遍历数组
	return 0;
}