
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int* data;
	int stackLow, stackTop;
}myStack;

/**
* ���������ǣ�����ʵ�֣�
* 
* level:������ǵĲ���
* 
* ����ѭ������ģ��ջ���˷�����������ǰ�����0��������ʶһ�����
*/
void yangHuiSanJiao(int level)
{
	if (level <= 0)
		return;
	myStack stack;
	int length = level + 2;
	stack.data = (int*)calloc(length,sizeof(int)); //Ԥ������0λ calloc��ʼ���ڴ�Ϊ��
	if (stack.data == NULL)
		return;
	stack.stackLow = 0;								  //��β
	stack.stackTop = 3;								  //��ͷ
	stack.data[1] = 1;								  //��ʼ�����飬ǰ����Ϊ 010
	//ֱ�������һ�У�����������һ
	int count = level;
	
	printf("%d \n",1);
	--count;
	while (count > 0) {


		//����β����λȡ�����
		int out = stack.data[stack.stackLow];
		stack.stackLow = (stack.stackLow + 1) % length;		//�ö�β�ڳ���������ѭ��
		int now = stack.data[stack.stackLow];
		int temp = out + now;


		//��������Ľ��д�뵽��ͷ����Ϊ��һ�е�����
		*(stack.data + stack.stackTop) = temp;              //ʹ�����鷽ʽ����ʾ��������ý����ý��
		stack.stackTop = (stack.stackTop + 1) % length;		//�ö�ͷ�ڳ���������ѭ��

		printf("%d ", temp);


		//�����ʱ��βȡ��0���㵽��һ�е�ĩβ���ڶ�ͷ��ӽ���0��Ȼ��������з�
		if (now == 0)
		{
			stack.data[stack.stackTop] = 0;
			stack.stackTop = (stack.stackTop + 1) % length;		//�ö�ͷ�ڳ���������ѭ��
			printf("\n");
			--count;
		}
	}
	free(stack.data);
}



int main(int cont, char* arg) {

	int count;
	scanf_s("%d",&count);   //scanf����ʾ����ȫ ����scanf_s���
	yangHuiSanJiao(count);	//int����ʾ��Χ���ޣ���Լ40�����������



	return 0;
}


