
#include <stdio.h>
#include <assert.h>



//				�ַ����ȼ��㣨���ź�����ƣ�
int my_strlen(const char* arr)
{
	assert(arr != NULL);
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}


int main()
{
	char arr[] = {"hello world 0"};
	printf("%d",my_strlen(arr));
}