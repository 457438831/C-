
#include <stdio.h>

extern void sum1();
extern void sum2();
int main()
{
	sum1();//����һ
	sum2();//������
}

//				�����ж��ٸ�һ
void sum1() {

	int num = 5;
	int i = 0;
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);//һ�������������һ���ڴ��л���ʧһ��һ
	}
	printf("��������1�ĸ��� %d\n",count);

	return 0;
}

//			���ж��ٸ�һ��ָ��λ��  �룩
void sum2(){

	int a = 5;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (1 == ((a >> i) & 1) ) { //��λ������    ��λ��    
			count++;//һ��������1Ϊ1���λΪ1���෴Ϊ��   
		}
	}
	printf("��������1�ĸ��� %d", count);
	return 0;
}