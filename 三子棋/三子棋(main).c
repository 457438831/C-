#include "Sgame.h"

void game() {
	int a = 0;
	char arr[ROW][COL] = {0};
	chushihua(arr,ROW,COL);//��ʼ������
	xianshi(arr,ROW,COL);//��ʾ
	while (1)
	{
		move(arr);//�����
		xianshi(arr, ROW, COL);//��ʾˢ��
		a = panduan(arr,ROW,COL);
		if (a != 'c')
		{
			break;
		}
		computermove(arr,ROW,COL);//������
		xianshi(arr,ROW,COL);//��ʾˢ��
		a = panduan(arr, ROW, COL);
		if (a != 'c')
		{
			break;
		}
	}
	if (a == '*') {
		printf("���Ӯ\n");
	}
	else if (a == '#') {
		printf("����Ӯ\n");
	}
	else {
		printf("ƽ��\n");
	}
}

void menu() {
	printf("********************\n");
	printf("***1:play  0:exit***\n");
	printf("********************\n");
}


void test() {
	srand((unsigned)time(NULL));
	int input = 1;
	do
	{
		menu(); //�˵�
		printf("��ѡ��-> ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("������1��0");
			break;
		}
	} while (input);
}
int main() {
	test();
}

