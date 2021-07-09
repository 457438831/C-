
#include <stdio.h>
#include <assert.h>



//   给定非负整数X数组形式，返回整数X+K数组形式(无动态内存)
void add(int* arr, int k, int size)
{
	assert(arr&&size);
	int remainder = 0;//余数
	int quotient = 0;//商
	for  (int i = 0;i < size; i++)
	{
		remainder = k % 10;
		quotient = k / 10;
		int up = arr[size-1-i] + remainder;//进数
		if (up>=10)
		{
			arr[size - 1 - i] = up % 10;  //如果余数加数组中的数大于10，将求余结果放到数组中 将商加到总商去
			quotient += up / 10;
		}
		else 
		{
			arr[size - 1 - i] = up;
		}
		if (quotient)				//如果商为零即跳出循环
			k = quotient;
		else
			break;
	}
}

void print(const int* arr,const int size)
{
	assert(arr && size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[] = {2,7,4};//思路：把数组看成一个整数  k取余数加数组最后一个数放到数组最后  商与倒数第二位继续取余加法
	int k = 181;
	int size = sizeof(arr) / sizeof(arr[0]);
	add(arr,k,size);
	print(arr,size);
	return 0;
}