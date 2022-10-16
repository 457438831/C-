
#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int* data;
	int stackLow, stackTop;
}myStack;

/**
* 输出杨辉三角（队列实现）
* 
* level:杨辉三角的层数
* 
* 利用循环数组模拟栈，此方法会在数据前后加上0，用作标识一层结束
*/
void yangHuiSanJiao(int level)
{
	if (level <= 0)
		return;
	myStack stack;
	int length = level + 2;
	stack.data = (int*)calloc(length,sizeof(int)); //预留两个0位 calloc初始化内存为零
	if (stack.data == NULL)
		return;
	stack.stackLow = 0;								  //队尾
	stack.stackTop = 3;								  //队头
	stack.data[1] = 1;								  //初始化数组，前三项为 010
	//直接输出第一行，并将行数减一
	int count = level;
	
	printf("%d \n",1);
	--count;
	while (count > 0) {


		//将队尾的两位取出相加
		int out = stack.data[stack.stackLow];
		stack.stackLow = (stack.stackLow + 1) % length;		//让队尾在长度数组中循环
		int now = stack.data[stack.stackLow];
		int temp = out + now;


		//将计算出的结果写入到队头，作为下一行的数据
		*(stack.data + stack.stackTop) = temp;              //使用数组方式会提示溢出，采用解引用解决
		stack.stackTop = (stack.stackTop + 1) % length;		//让队头在长度数组中循环

		printf("%d ", temp);


		//如果此时队尾取到0，便到达一行的末尾，在队头添加结束0，然后输出换行符
		if (now == 0)
		{
			stack.data[stack.stackTop] = 0;
			stack.stackTop = (stack.stackTop + 1) % length;		//让队头在长度数组中循环
			printf("\n");
			--count;
		}
	}
	free(stack.data);
}



int main(int cont, char* arg) {

	int count;
	scanf_s("%d",&count);   //scanf会提示不安全 采用scanf_s解决
	yangHuiSanJiao(count);	//int数表示范围有限，大约40几层后产生溢出



	return 0;
}


