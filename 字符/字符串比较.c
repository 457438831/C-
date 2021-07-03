
#include <stdio.h>
#include <assert.h>


//		strcmp  �ַ�����С�ж�(�Ƚϵ����ַ���ASCLL��ֵ)
int my_strcmp(const char* arr1,const char* arr2)
{//
	assert(arr1 && arr2);
	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')//arr1�󷵻�����  ��ȷ���0    arr1С���ظ���
			return 0;
		arr1++;
		arr2++;
	}
	return *arr1 - *arr2;
}

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcde";
	int ret = my_strcmp(arr1,arr2);
	if (ret > 0)
	{
		printf("arr1 > arr2");
	}
	else if (ret == 0)
	{
		printf("arr1 = arr2");
	}
	else {
		printf("arr1 < arr2");
	}
	return 0;
}