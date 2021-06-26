#include "Sgame.h"

void game() {
	int a = 0;
	char arr[ROW][COL] = {0};
	chushihua(arr,ROW,COL);//初始化数据
	xianshi(arr,ROW,COL);//显示
	while (1)
	{
		move(arr);//玩家走
		xianshi(arr, ROW, COL);//显示刷新
		a = panduan(arr,ROW,COL);
		if (a != 'c')
		{
			break;
		}
		computermove(arr,ROW,COL);//电脑走
		xianshi(arr,ROW,COL);//显示刷新
		a = panduan(arr, ROW, COL);
		if (a != 'c')
		{
			break;
		}
	}
	if (a == '*') {
		printf("玩家赢\n");
	}
	else if (a == '#') {
		printf("电脑赢\n");
	}
	else {
		printf("平局\n");
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
		menu(); //菜单
		printf("请选择：-> ");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("请输入1或0");
			break;
		}
	} while (input);
}
int main() {
	test();
}

