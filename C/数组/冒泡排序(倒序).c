#include <stdio.h>


//ð�����򣨵���
// 
//����   �Ӻ���ǰ������ ������
void reverse(int arr[], int sz)
{
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		int a = 1;//����
		int i = sz - 1;//MAXԪ���±�
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
		if (a)//���Ԫ�ز���Ҫ���� ������ 
		{
			break;
		}
	}
}
//���
void print(int arr[],int sz) 
{
	int i = 0;
	for ( i = 0; i < sz; i++)//�������鲢��ӡ
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[10] = {5,9,6,8,4,7,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);//��������Ԫ�ظ���
	reverse(arr,sz);//����
	print(arr,sz);//���
	return 0;
}