
#include <stdio.h>

//			�������������Ʋ���ͬ����
int get_number(int a, int b)
{
	int c = 0;
	int count = 0;
	c = a ^ b;//�����  ��ͬΪ�㲻ͬΪһ   ��������м���һ����
	while (c)
	{
		c = c & (c - 1); //��
		count++;
	}
	return count;
}

int main()
{
	int a = 5;
	int b = 10;
	int count = 0;
	count = get_number(a,b);
	printf("�У�%d λ��һ��",count);
	return 0;
}

