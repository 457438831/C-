//  函数实现
#include "Sgame.h"

//初始化
void chushihua(char arr[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int k = 0;
		for (k = 0; k < col; k++)
		{
			arr[i][k] = ' ';
		}
	}
}

//显示 show
void xianshi(char arr[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int b = 0;
		for (b = 0; b < col; b++)
		{
			printf(" %c ",arr[i][b]);
			if (b < col-1)
				printf("|");
		}
		printf("\n");
		if (i < row-1 ) {
			int c = 0;
			for (c = 0; c < col; c++)
			{
				printf("---");
				if (c < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//  落子
void move(char arr[ROW][COL]) {
	int row = 0;
	int col = 0;
	while (1)
	{
		printf("请输入坐标：");
		scanf("%d%d", &row, &col);
		if (row >= 1 && row <= ROW && col >= 1 && col <= COL)
		{
			if (arr[row - 1][col - 1] == ' ') {
				arr[row - 1][col - 1] = '*';
				break;
			}
			else
			{
				printf("该位置有棋子！");
			}
		}
		else
		{
			printf("坐标不合法，请重新输入");
		}
	}
}


//电脑随机下子
void computermove(char arr[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
	}
}

//   判断结果
// 继续返回 c  玩家赢返回*   电脑赢返回#  棋盘满返回p
int panduan(char arr[ROW][COL], int row, int col) {
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ') 
			return arr[i][0];
	}
	//判断列
	for (i = 0; i < col; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	//判断斜三格
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != ' ')
		return arr[2][0];
	//判断是否填满
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++) {
			if (arr[a][b] == ' ') {
				return 'c';
			}
		}
	}
	return 'p';
}
