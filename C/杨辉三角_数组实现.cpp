

#include<stdlib.h>
#include<stdio.h>

#define DataType unsigned int 

/**
* 
* ������ǣ�������ʵ��
* 
* level:������ǵĲ���
* 
*/
void yangHuiSanJiao(int level)
{	
	if (level <= 0)
		return;
	DataType* data = (DataType*)calloc(level,sizeof(DataType));  //�����������ȵĴ�С
	if (data == NULL)
		return;

	//��ʼ������
	data[0] = 1;
	//�㼶
	for (int i = 0; i < level; i++)
	{	//ÿһ�������
		for (int j = i ;j >= 0; --j)
		{	//�������һ��Ԫ��ֱ�ӷ���ֵ
			if (j == 0)
			{
				printf("%d ", data[0]);
				break;
			}
			//�Ӻ���ǰ����
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
