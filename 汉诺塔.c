#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>



//				��ŵ��ʵ��
// ��Ϊ����
//    �ƶ�N-1�� ��x����z�ŵ�y��
//	  �ƶ�X��ʣ�µ�һ����y��
//    ��y�ϵ�n-1������x�ŵ�y��
void move(char c1, char c2) {
	printf("%c -> %c\n", c1, c2);
}

void hanoi(int n,char x,char y ,char z) {
	if (n == 1) {
		move(x,z);
	}
	else {
		hanoi(n-1,x,z,y);
		move(x,z);                  //��ŵ������
		hanoi(n-1,y,x,z);
	}
}

int main() {
	int n = 0;
	int yes= 0;
jixu:
	system("cls");
	printf("please input n: ");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	printf("�Ƿ������1:yes  0:no \n->");
	scanf("%d", &yes);
	if (yes == 1) {
		goto jixu;
	}
	return 0;
}
