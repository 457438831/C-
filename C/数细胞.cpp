
#include<stdio.h>

/**
* 数细胞规则，上下左右相连接的为一个细胞
* 
*/
#define level 4
#define child 10

void delCells(int cells[level][child],int le,int ch) {
	
	if (cells[le][ch] != 0)
	{
		cells[le][ch] = 0;
	}
	else {
		return;
	}
	//上
	if(le - 1 >= 0 )
	delCells(cells, le - 1, ch);
	//下
	if (le + 1 < level)
	delCells(cells, le + 1, ch);
	//左
	if (ch - 1 >= 0)
	delCells(cells, le, ch - 1);
	//右
	if (ch + 1 < child)
	delCells(cells, le, ch + 1);

}

void findCellsD(int cells[level][child]) {
	
	int count = 0;
	for (int i = 0; i < level; i++)
	{
		for (int j = 0; j < child; j++)
		{
			if (cells[i][j] != 0) {
				delCells(cells, i, j);
				++count;
			}
		}
	}
	printf("一共有：%d 个细胞！", count);
}

int main(int argc,char* argv) {

	//初始化数组
	int cells[level][child] = {
		{1,1,1,1,1,0,0,0,1,1},
		{1,0,1,1,1,1,1,1,0,0},
		{1,0,1,1,1,0,0,1,1,1},
		{0,0,0,0,0,0,0,0,1,1} };

	findCellsD(cells);

	return 0;
}