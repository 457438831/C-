
#include <stdio.h>

//    �ַ����鷴ת���ݹ鷨��


//�Զ����ַ����Ⱥ���
int my_string(char arr[])
{
	char* p = arr;
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}

//��ת�ַ���
void reverse_string(char arr[])
{
	char tmp = arr[0];  //����һ��Ԫ�ظ�tmp
	int sz = my_string(arr);
	arr[0] = arr[sz - 1];//  �����һ��Ԫ���õ���һ����Ȼ�󽫡�\0�������һ��Ԫ��
	arr[sz - 1] = '\0';
	if (sz - 1 > 1) {//    ��Ϊ'\0'�����һ��Ԫ�أ�����������һ
		reverse_string(arr + 1);//  ָ������ƶ�һλ ����������
	}
	arr[sz - 1] = tmp;
}

void print(char arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
}

int main()
{
	char arr[] = {"abcdefg"};
	int sz = my_string(arr);//��ȡ�ַ�����  
	reverse_string(arr);//��ת����
	print(arr,sz);
	printf(" ���У�%d���ַ�", sz);
	return 0;
}