#include <stdio.h>


//				�ж����꼰�������Ż����룩
int main() {
	int year = 0;
	int count = 0;
	for (year = 1000; year <=2000; year++)
	{
		//�ж�����Ĺ���
		//1,�ܱ�4�����Ҳ��ܱ�100����
		//2,�ܱ�400����
		if (( 0 == year % 4 && 0 != year % 100) || ( 0 == year % 400)) {
			printf("%d  ",year);
			count++;
		}
	}
	printf("�����У�%d ��",count);
	return 0;
}


