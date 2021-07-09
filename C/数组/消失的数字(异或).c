

#include <stdio.h>


//		消失的数字     时间复杂度O(n)  异或
// 数组中包含0--n的整数，其中有一个数没有 
// 
//思路：一个数异或相同数之后还是本身，所以先异或完整数组然后再异或缺少的数组剩下的就是原本的数组
int main()
{
	int arr[] = { 5,4,3,1,0 ,2};
	int length = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	int i = 0;
	for (i = 0; i < length + 1; i++)
	{
		sum = sum ^ i;		//将完整数组异或
	}
	for  (int j = 0;j < length;j++)
	{
		sum = sum ^ arr[j];	//异或消失元素的数组
	}
	printf("差一个数是:%d",sum);
	return 0;
}