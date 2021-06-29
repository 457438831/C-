
#include <stdio.h>
#include <assert.h>



//   �����Ǹ�����X������ʽ����������X+K������ʽ(�޶�̬�ڴ�)
void add(int* arr, int k, int size)
{
	assert(arr&&size);
	int remainder = 0;//����
	int quotient = 0;//��
	for  (int i = 0;i < size; i++)
	{
		remainder = k % 10;
		quotient = k / 10;
		int up = arr[size-1-i] + remainder;//����
		if (up>=10)
		{
			arr[size - 1 - i] = up % 10;  //��������������е�������10�����������ŵ������� ���̼ӵ�����ȥ
			quotient += up / 10;
		}
		else 
		{
			arr[size - 1 - i] = up;
		}
		if (quotient)				//�����Ϊ�㼴����ѭ��
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
	int arr[] = {2,7,4};//˼·�������鿴��һ������  kȡ�������������һ�����ŵ��������  ���뵹���ڶ�λ����ȡ��ӷ�
	int k = 181;
	int size = sizeof(arr) / sizeof(arr[0]);
	add(arr,k,size);
	print(arr,size);
	return 0;
}