
#include <stdio.h>
#include <assert.h>


// strstr �����ַ����Ƿ����   (�Զ���) �������±�
int my_strstr(const char* arr1,const char* arr2)
{
	assert(arr1 && arr2);
	const char* string = arr1;
	const char* find = arr2;
	const char* log = arr1;
	//recording count  ��¼�±�
	int count = 0;						//���ڼ�¼Logָ���ƶ��Ĵ��������±�
	if (0 == *find)					    //���arr2Ϊ'\0'��0���������
		return -1;
	while (*string)						//�����ҵ��ַ�������Ϊ�ռ�'\0'
	{
		string = log;					//log���ڼ�¼���ҵ�λ��
		find = arr2;					//ÿ�αȽ�����findָ��λ������ʼλ��
		while (*string == *find)
		{
			if (*string == '\0')
			{//	ĩβ���
				return count;
			}
			string++;
			find++;
		}
		//    �м����
		if (*find == '\0')
			return count;
		count++;
		log++;
	}
	//  �����
	return -1;
}

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcd";
	int find = my_strstr(arr1,arr2);
	if (find != -1)
	{
		printf("find���±���:%d",find);
	}
	else {
		printf("not find");
	}
	return 0;
}