#include <stdio.h>
#include <assert.h>



//realization of string length   �ַ�������ʵ��
//recursive method   �ݹ鷽��

int my_strlen(const char* arr)
{
	assert(arr);
	if (*arr)//��Ϊ�ַ�����βĬ�ϴ洢'\0'��ASCLL��ֵΪ0  ��Ϊ�����ʾ�г���
	{
		return 1 + my_strlen(arr + 1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "abcd";
	printf("%d", my_strlen(arr));
	return 0;
}