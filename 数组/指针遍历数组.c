
#include <stdio.h>


//				指针遍历数组
void print(int* p, int sz) 
{
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d ",*(p + i));//指针加整数  +1即跳过一个当前指针类型大小
	}
}

int main()
{
	int arr[] = {1,2,30,1565,15678,22};
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr,sz);
	return 0;
}
