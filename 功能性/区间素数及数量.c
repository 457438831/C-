#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>


//                 ��������������
//		������ֻ�ܱ�1�ͱ�����������
int main() {
	int i = 0;
	int count = 0;
	int left= 0;
	int rigth = 0;
	scanf("%d%d",&left,&rigth);
	for (i = left; i <=rigth; i++)
	{
		int b = 0;
		for (b = 2; b <= sqrt(i); b++)
		{
			if (i % b==0) {
				break;
			}
		}
		if (b > sqrt(i)) {
			printf("%d ", i);
			count++;
		}
	}
	printf("�����У�%d ��",count);
	return 0;
}