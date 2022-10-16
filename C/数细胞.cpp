
#include<stdio.h>

/**
* ��ϸ�������������������ӵ�Ϊһ��ϸ��
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
	//��
	if(le - 1 >= 0 )
	delCells(cells, le - 1, ch);
	//��
	if (le + 1 < level)
	delCells(cells, le + 1, ch);
	//��
	if (ch - 1 >= 0)
	delCells(cells, le, ch - 1);
	//��
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
	printf("һ���У�%d ��ϸ����", count);
}

int main(int argc,char* argv) {

	//��ʼ������
	int cells[level][child] = {
		{1,1,1,1,1,0,0,0,1,1},
		{1,0,1,1,1,1,1,1,0,0},
		{1,0,1,1,1,0,0,1,1,1},
		{0,0,0,0,0,0,0,0,1,1} };

	findCellsD(cells);

	return 0;
}