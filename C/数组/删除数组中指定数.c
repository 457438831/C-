#include <stdio.h>
#include <assert.h>


//ɾ��������ָ����
void delnum(int* arr,const int num,int* size)
{
	assert(arr&&size);
	int* start = arr;//����һ��ָ������ָ��Ϊnum����
	int cont = *size;
	int i = 0;
	for (i = 0; i < cont; i++)
	{
		if (arr[i] != num)//���������ָ�������arrֵ��start  ����ͬ��������
		{
			*start = arr[i];
			start += 1;
		}
		else if (arr[i] == num)//���ֵΪnum��size-1��ȥ��һ����
		{
			*size -=1;
		}
	}
	while (1)
	{
		if (cont > *size)//�ж��ж��ٸ���ͬ��   ��������n����ͬ����Ϊ0
		{
			arr[(cont - 1)] = 0;
			cont--;
		}
		else
		{
			break;
		}
	}
}

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int num = 10;//ָ����
	int arr[] = {0,10,10,10,10,2,10,10,10,10,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	delnum(arr,num,&size);//ɾ��������ָ����  ���޸�����
	print(arr,size);//��ӡ
	return 0;
}