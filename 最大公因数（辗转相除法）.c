#define _CRT_SECURE_NO_WARNINGS 1  //vs�༭����Ϊscanf����ȫ ���峣��ֵ���ɹ�ܱ���������
#include <stdio.h>



//			շת��������������
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d",&a,&b);
	while (c = a%b) {  // ���a>b����a b��ֵ��a��λ�õ��� Ȼ��ͽ���շת�����
		a = b;
		b = c;    //շת�����������/С�� = �̡�������  Ȼ����С��/���� һֱѭ��������Ϊ�����������
				//�������
	}
	printf("���Լ��Ϊ��%d",b);
	return 0;
}