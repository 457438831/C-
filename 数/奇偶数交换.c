
#include <stdio.h>
#include <assert.h>

// ����ż������(������ǰż���ں�)
void jioupaixu(int* arr,const int len)
{
	assert(arr&&len);
	//�������һ������
	//���ұ���һ��ż��
	//����
	int* left = arr;//��Ԫ��ָ��
	int* rigth = &arr[len - 1];//βԪ��ָ��
	int i = 0;
	while (left < rigth)
	{
		if (*left % 2)
		{
			left++;//������Ϊ1������  �򲻱� �ж���һ��Ԫ��
		}
		else
		{  //���leftΪż����rigth��ʼ����һ��������������
			if (*rigth % 2)
			{
				int tmp = *left;
				*left = *rigth;
				*rigth = tmp;
			}
			else
			{
				rigth--;//������Ϊ0��ż��  �򲻱� �ж���һ��Ԫ��
			}
		}
	}
}

void print(const int* arr,const int sz)
{
	assert(arr&&sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr) / sizeof(arr[0]);
	jioupaixu(arr,sz);
	print(arr,sz);
	return 0;
}