#include <stdio.h>


//			求数组内最大值（最小值类似）
int main() {
	int arr[] = {-1,2,3,4,5,6,20,8,9,100};
	int max = arr[0];
	int length = sizeof(arr) / sizeof(arr[0]);//求数组元素个数
	int i = 0;
	for (i = 1; i < length; i++)
	{
		if (max < arr[i]){
			max = arr[i];
		}
	}
	printf("max=%d",max);
	return 0;
}
