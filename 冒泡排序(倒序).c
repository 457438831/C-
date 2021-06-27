#include <stdio.h>


//冒泡排序（倒序）
// 
//排序   从后往前排升序 即倒序
void reverse(int arr[], int sz)
{
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		int a = 1;//开关
		int i = sz - 1;//MAX元素下表
		for (; i > 0; i--)
		{
			if (arr[i - 1] < arr[i])
			{
				int tmp = 0;
				tmp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tmp;
				a = 0;
			}
		}
		if (a)//如果元素不需要调换 即返回 
		{
			break;
		}
	}
}
//输出
void print(int arr[],int sz) 
{
	int i = 0;
	for ( i = 0; i < sz; i++)//遍历数组并打印
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[10] = {5,9,6,8,4,7,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组元素个数
	reverse(arr,sz);//排序
	print(arr,sz);//输出
	return 0;
}