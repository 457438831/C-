
#include <stdio.h>
#include <assert.h>




//		 ʵ���ڴ濽��

/*��������ͬ���� ���ݿ���  ��ճ��Ŀ�꣬����Ŀ�꣬�������ȣ�*/
void my_memcpy(void* dest, const void* rst, size_t len)
{
	assert(dest && rst);
	while (len--)
	{
		*(char*)dest = *(char*)rst;
		++(char*)dest;
		++(char*)rst;
	}
}

//		ʵ����һ�������п�������

/*��ͬһ������ ���ݿ��� ��ճ��Ŀ�꣬����Ŀ�꣬�������ȣ�*/
void my_memmove(void* dest, const void* rst, size_t len)
{
	assert(dest && rst);
	if (dest < rst)				//Ŀ�ĵ���Դͷ��ǰ��  �ӵ�һ����ʼ����
	{
		my_memcpy(dest, rst, len);
	}
	else						//  ����������Ӻ���ǰ����
	{
		char* in = ((char*)dest) + len - 1;
		char* go = ((char*)rst) + len - 1;

		while (len--)
		{
			*in = *go;
			go--;
			in--;
		}
	}
}

//����������е���������
void intpt()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, sizeof(arr1));	//��arr1��������� ������arr2������
	for (size_t i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++)
	{
		printf("%d ", arr2[i]);
	}
}

// ����������е��ַ�������
void copystr()
{
	char str1[] = "������ɽ��";
	char str2[11] = { 0 };
	my_memcpy(str2, str1, sizeof(str1));  //��str1�ַ����е����ݿ�����str2��
	printf("%s ", str2);
}

// ��һ�������ڽ��еĿ���
void copyone()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 16);	//��arr��ʼ����(����ʼλ��)  ��arr[2]��λ�� ����Ϊ16�ֽ�(��4��int)
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	intpt();						//�������鿽��
	printf("\n");
	copystr();						//�ַ������鿽��
	printf("\n");
	copyone();						//��������  ��ͬһ������
	return 0;
}