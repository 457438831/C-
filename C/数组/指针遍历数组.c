
#include <stdio.h>


//				ָ���������
void print(int* p, int sz) 
{
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d ",*(p + i));//ָ�������  +1������һ����ǰָ�����ʹ�С
	}
}

int main()
{
	int arr[] = {1,2,30,1565,15678,22};
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr,sz);
	return 0;
}
