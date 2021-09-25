

#include "KMP.h"

void Table(const char*, int*,int);//����KMP��

int main()
{
	char str[] = "abcdefgaba";
	char findStr[] = "ef";
	int item;
	if ((item = KMP(str, findStr)) >= 0)
		printf("�±�Ϊ:%d", item);
	else
		printf("Not Fonut");
	return 0;
}

int KMP(const char* str,const char* findStr)//KMP�㷨
{
	assert(str);
	assert(findStr);
	//���ɱ�
	int length = strlen(findStr);
	int* arr = (int*)malloc(sizeof(int)*length);
	if (!arr)return -1;
	Table(findStr,arr,length);
	//����Ԫ��
	int i = 0;
	int j = 0;
	while (1)
	{
		for (; str[i] == findStr[j] && findStr[j] != 0; i++,j++);
		if (!findStr[j])
		{
			free(arr);
			return i-length;
		}else if (!str[i]) 
		{
			free(arr);
			return -1;
		}
		if (j == 0)i++;
		else j = (arr[j - 1] + 1);
	}
}

void Table(const char* findStr, int* arr,int length)
{
	int previous=0,i=1;
	arr[0] = -1;
	while (--length)
	{
		if (findStr[previous] != findStr[i])
		{
			if (!(arr[previous]+1))
			{
				arr[i] = -1;
				i++;
			}
			else {
				previous = arr[previous - 1] + 1;
				continue;
			}
		}else
		{
			arr[i] = previous;
			i++;
		}
		previous = arr[i - 1] + 1;
	}
}