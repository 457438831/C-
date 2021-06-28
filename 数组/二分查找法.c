#include <stdio.h>


//二分查找法
int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int want = 10;
	int left = 0;//左下标
	int rigth = sizeof(arr) / sizeof(arr[0])-1;//右下标
	while (left<=rigth) {
		int mid = (left + rigth) / 2;  //取中间值
		if (arr[mid] > want) 
		{
			rigth = mid -1;
		}
		else if (arr[mid] < want) 
		{
			left = mid +1;
		}
		else if(arr[mid] == want)
		{
			printf("下标是：%d\n", mid);
			break;
		}
	}
	if (left>rigth)
	{
		printf("未找到！");
	}
	return 0;
}