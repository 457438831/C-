
#include <stdio.h>
#include <assert.h>

//strcat  �ַ���׷��
//ȱ�㣺Ŀ��ռ䲻����ͻ������Դ�ַ����������'\0',��Ϊ��ָ��������Բ����Լ�׷���Լ�
void my_strcat(char* arr1,const char* arr2)
{
	assert(arr1 && arr2);

	char* ret = arr1;
	//find '\0'
	while (*arr1++);//�Ƚ�������++  ���ҵ�'\0'ʱָ����++�� ������Ҫ--
	arr1--;
	//cat strings
	while (*arr1++ = *arr2++);//Ȼ�����ݿ������ַ����� ����'\0'

	return ret;  //����ָ����ʼλ��
		
}

int main()
{
	char arr1[20] = "abcd";
	char arr2[] = "efgh";
	my_strcat(arr1,arr2);
	printf("%s",arr1);
	return 0;
}