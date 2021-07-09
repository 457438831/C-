
#include <stdio.h>


//		消失的数字     时间复杂度O(n)
// 数组中包含0--n的整数，其中有一个数没有 
// 
//思路：遍历0--n的所有数并相加  减去 数组总和即为少的那一个数
int main()
{
	int arr[] = {5,4,3,1,0};
	int length = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	int i = 0;
	for (i = 0; i < length + 1; i++) //因为消失了一个数所以长度加一
	{
		if (i == length)//如果i==length即数组已经遍历到最后一个数，继续遍历会指针越界非法访问
		{
			sum = sum + i;   //因为遍历的是完整数组  即多出来的一个元素加到结果去
			break;
		}
		sum = sum + ( i - arr[i] );   //将每位数的差相加
	}
	printf("差一个数是:%d ",sum);
	return 0;
}