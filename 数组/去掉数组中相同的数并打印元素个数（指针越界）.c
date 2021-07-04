

#include <stdio.h>
#include <assert.h>
//			ȥ����������ͬ��������ӡԪ�ظ�����ָ��Խ�磩
int dels(int* arr, int size)
{
	assert(arr&&size);
	int left = 0;			//��ʼ����Ƚ�Ԫ�ص��±�
	int right = 1;			//��ʼ���ұȽ�Ԫ�ص��±�
	int num = 0;			//��ʼ����ͬԪ�س���
	while (right < size)
	{
		if (arr[left] != arr[right])
		{
			arr[num] = arr[left];
			left++;
			right++;
			num++;
		}
		else
		{
			left++;
			right++;
		}
	}
	arr[num] = arr[left];//�����ͬ����ѭ����δ��ֵ rightԽ�� leftָ�����һ��Ԫ��    ����ͬ��ѭ���ڸ�ֵ num++ rightԽ�� leftָ�����һ��Ԫ��
	num++;
	return num;//��Ϊnumʼ�ձ���Ԫ�ص��±��1�� ��ΪԪ�ظ���
}

//��������
void print(const int arr[],const int num)
{
	assert(arr);
	for (int i = 0; i < num; i++)
	{
		printf("%d",arr[i]);
	}
}

int main()
{
	int arr[] = { 1,2,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = dels(arr,size);       //ɾ���ظ�Ԫ�ز�����Ԫ�ظ���
	printf("��������:%d������ͬ��Ԫ��\n",num);
	print(arr,num);                 //��������
	return 0;
}