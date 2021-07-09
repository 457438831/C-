#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>
#include <time.h>


			/*猜数字游戏*/
void menu() {
	printf("*******************************\n");
	printf("*****1：开始游戏    0：退出****\n");
	printf("*******************************\n");	
}

void game() {
	int number = rand()%100+1;//随机生成1-100的数字
	int a = 0;
	while (1)
	{
		printf("请猜数字,>");
		scanf("%d", &a);
		if (a > number) {
			system("cls");
			printf("大了！");
		}
		else if (a < number) {
			system("cls");
			printf("小了！");
		}
		else {
			break;
		}
	}
}

int main() {
	srand((unsigned)time(NULL));//初始化
	int input = 0;
	do
	{
		menu();//菜单
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			system("cls");//清屏
			for (; input == 1;) {
				game();
				system("cls");
				printf("*******************************\n");
				printf("***恭喜你猜对了！***\n");
				printf("*******************************\n");
				printf("是否继续游戏？1:继续游戏  0:退出 ->");
				scanf("%d", &input);
				system("cls");
			}
			break;
		case 0:
			printf("退出游戏");
			break;
		default :
			printf("输入有误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}
