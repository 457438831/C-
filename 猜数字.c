#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <time.h>


			/*��������Ϸ*/
void menu() {
	printf("*******************************\n");
	printf("*****1����ʼ��Ϸ    0���˳�****\n");
	printf("*******************************\n");	
}

void game() {
	int number = rand()%100+1;//�������1-100������
	int a = 0;
	while (1)
	{
		printf("�������,>");
		scanf("%d", &a);
		if (a > number) {
			system("cls");
			printf("���ˣ�");
		}
		else if (a < number) {
			system("cls");
			printf("С�ˣ�");
		}
		else {
			break;
		}
	}
}

int main() {
	srand((unsigned)time(NULL));//��ʼ��
	int input = 0;
	do
	{
		menu();//�˵�
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			system("cls");//����
			for (; input == 1;) {
				game();
				system("cls");
				printf("*******************************\n");
				printf("***��ϲ��¶��ˣ�***\n");
				printf("*******************************\n");
				printf("�Ƿ������Ϸ��1:������Ϸ  0:�˳� ->");
				scanf("%d", &input);
				system("cls");
			}
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default :
			printf("�����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}
