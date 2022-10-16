

#include<stdlib.h>
#include<stdio.h>

#define DataType unsigned int 

/**
* 
* 杨辉三角，用数组实现
* 
* level:杨辉三角的层数
* 
*/
void yangHuiSanJiao(int level)
{	
	if (level <= 0)
		return;
	DataType* data = (DataType*)calloc(level,sizeof(DataType));  //创建与阶数相等的大小
	if (data == NULL)
		return;

	//初始化数据
	data[0] = 1;
	//层级
	for (int i = 0; i < level; i++)
	{	//每一层的数据
		for (int j = i ;j >= 0; --j)
		{	//如果到第一个元素直接返回值
			if (j == 0)
			{
				printf("%d ", data[0]);
				break;
			}
			//从后往前计算
			data[j] = data[j] + data[j - 1];
			printf("%d ",data[j]);
		}
		printf("\n");
	}
}




int main(int count, char* args) {

	yangHuiSanJiao(40);

	return 0;
}
