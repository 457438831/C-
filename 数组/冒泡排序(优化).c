#include <stdio.h>



//				冒泡排序法(效率优化)
void maopao(int arr[], int length) {//数组传递参数 只传递第一个值的地址值
	int i = 0;
	for (i = 0; i < length; i++)
	{
		int flag = 1;// 用于判断是否已经有序
		int b = 0;
		for (b = 0; b < length-1-i; b++)//如果length只减一会有多余计算，不是最优
		{
			if (arr[b] > arr[b + 1]) {
				int tmp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int i = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	maopao(arr,length);
	for (i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}