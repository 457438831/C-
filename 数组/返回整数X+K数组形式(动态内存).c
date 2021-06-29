#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//   �����Ǹ�����X������ʽ����������X+K������ʽ(��̬�ڴ�)


int Max_length(int k, const int size)  //������󳤶�
{
	assert(size);
	int count = 0;
	while (k)
	{
		k /= 10;
		count++;
	}
	if (size > count)
		return size;
	else
		return count;
}

int* add(int* arr, int k, int* size)
{
	assert(arr && size);
	int remainder = 0;//����
	int quotient = 0;//��
	int Initsize = *size;
	*size = Max_length(k, *size) + 1;
	int* Newarr = (int*)calloc(*size, 4);//���������+1�ĳ���
	if (Newarr == NULL)
	{
		printf("�ڴ濪��ʧ��: %s", strerror(errno));
		return NULL;
	}
	else
	{
		int* init = Newarr;
		for (int i = 0; i < Initsize; i++)  //��ԭ���ݿ������¿ռ�
		{
			Newarr[*size - 1 - i] = arr[Initsize - 1 - i];
		}
		arr = init;
		printf("�ڴ濪�ٳɹ�");
	}

	for (int i = 0; i < *size; i++)
	{
		remainder = k % 10;
		quotient = k / 10;
		int up = arr[*size - 1 - i] + remainder;//����
		if (up >= 10)
		{
			arr[*size - 1 - i] = up % 10;  //��������������е�������10�����������ŵ������� ���̼ӵ�����ȥ
			quotient += up / 10;
		}
		else
		{
			arr[*size - 1 - i] = up;
		}
		if (quotient)				//�����Ϊ�㼴����ѭ��
		{
			k = quotient;
		}
		else
			return arr;
	}
	return NULL;
}

void print(int* arr, const int size)
{
	assert(arr && size);
	if (arr[0] == 0)
	{
		for (int i = 1; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	else {
		for (int i = 0; i < size; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	free(arr);				//���������ʹ�ö�̬�ռ�ĵط�  �����������ͷ�
	arr = NULL;
}

int main()
{
	int arr[] = { 9,9,9,9,9,9,9,9,9,9 };//˼·���ص�ʲôʱ�򿪱ٿռ� 1 ������֮ǰ ���Ͳ���Ų�����ݣ���ֱ�Ӵ���һ������󳤶ȶ�һ�����顿�ص���ô��������󳤶ȣ�����ʮ��¼����   2��������ʱ ����ҪŲ�����ݣ�
	int k = 1;
	int size = sizeof(arr) / sizeof(arr[0]);
	int* Arr = add(arr, k, &size);
	print(Arr, size);
	return 0;
}