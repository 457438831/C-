#include <stdio.h>


//				�Զ��庯�������ַ������ȣ������� ĩָ���ַ  ��  ʼָ���ַ = �м�Ԫ��
int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end !='\0')
	{
		end++;
	}
	return end - start;
}

int main()
{
	char arr[] = {"������ɽ��,�ƺ��뺣��,����ǧ��Ŀ,����һ��¥"};
	int len = 0;
	len = my_strlen(arr);
	printf("%d",len);

	return 0;
}