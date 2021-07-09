
#include <stdio.h>
#include <assert.h>


//     ȥ����������ͬ��������ӡԪ�ظ�����ָ�벻Խ�磩
//	˼·������1��2��3��ָ�룬����12ָ����������Ƚϣ�3��¼��������±��ֹԽ�磬����ͬ��Ԫ�����·ŵ�������
//  �޸���ԭ����   �Ҳ�δɾ�������ظ�Ԫ��
int dels(int* arr,const int size)
{
	assert(arr);
	int* left = arr;                //�Ƚ�ָ����
	int* right = arr + 1;           //�Ƚ�ָ����
	int* end = arr + size - 1;      //�������λ��
	int count = 0;                  //������

	for (int i = 0; i < size-1; i++)//��Ϊ�������Ƚ�����ֻ��Ҫ�Ƚ�size-1��
	{
		if (*left == *right)        //��������Ƚ�����ȼ��Ƚ�ָ������ƶ�һλ
		{
			if (right != end)       //�жϱȽ�ָ�����Ƿ񵽴�����߽�    ��ֹԽ�����
			{
				right++;
				left++;
			}
		}
		else                        //�������Ⱦͽ��Ƚ�ָ�����ֵ��arr
		{
			*arr = *left;
			arr++;
			count++;
			if (right != end)       //�жϱȽ�ָ�����Ƿ񵽴�����߽�    ��ֹԽ�����
			{
				right++;
				left++;
			}
		}
	}
	*arr = *right;                  //��������λ��ͬ ����ѭ����û��ȡֵ���ڴ˽�left��right��ֵ�����ظ�ָ��
	count++;                        //��������λ��ͬ������ѭ�����Ѿ���leftֵ�������ظ�ָ�룬��ʱֻ��Ҫ��rightֵ�������ظ�ָ�뼴��
	return count;
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
	int arr[] = {1,2,2,3,3,3,4,4,4,4,5,5,5,5,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = dels(arr,size);       //ɾ���ظ�Ԫ�ز�����Ԫ�ظ���
	printf("��������:%d������ͬ��Ԫ��\n",num);
	print(arr,num);                 //��������
	return 0;
}