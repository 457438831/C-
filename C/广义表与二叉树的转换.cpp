
/*

	广义表表示二叉树

	A(B(,D),C(E,F(G)))  表示二叉树
	遇到正常数据 创建节点，并根据条件添加到指定位置

	功能：输入广义表示法，创建二叉树，并输出广义表示法
*/


#include<stdio.h>
#include <malloc.h>

#define STACK_LENGTH 10

//节点
struct node {
	node *left,*rigth;
	char data;
};

//二叉树转换广义表
void toGuangYi(node* tree) {

	if (tree == NULL)
		return;
	printf("%c", tree->data);
	if (tree->left != NULL || tree->rigth != NULL) {
		printf("(");
		//左
		if (tree->left != NULL)
			toGuangYi(tree->left);

		//右
		if (tree->rigth != NULL)
		{
			printf(",");
			toGuangYi(tree->rigth);
		}
		printf(")");
	}
}

//释放内存
void myFree(node* tree) {
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		myFree(tree->left);
	if (tree->rigth != NULL)
		myFree(tree->rigth);
	free(tree);
}

//广义表转二叉树
void GuangYiTo() {
	node* stack[STACK_LENGTH];
	char read;//读取输入字符
	node* newNode = NULL;//保存新创建的节点
	int stackTop = 0;//stack栈顶
	int where = 1;//方向，1左，2右
	node* tree = NULL;
	int yesOrNo = 1;
	while (yesOrNo) {
		read = getc(stdin);
		
		switch (read) {
			case '(': //将新节点加入栈中 并将标记改为左
				stack[stackTop++] = newNode;
				where = 1;
				break;

			case ','://将标记改为右
				where = 2;
				break;

			case ')'://将栈顶元素出栈,并将栈顶减一
				stack[--stackTop] = NULL;
				if (stackTop == 0)
					yesOrNo = 0;
				break;

			default://如果以上都不满足，默认为正常数据  创建该数据的节点 并根据方向添加到栈顶元素的相对位置
				newNode = (node*)malloc(sizeof(node));
				if (newNode == NULL)
					return;
				newNode->data = read;
				newNode->left = NULL;
				newNode->rigth = NULL;

				if (stackTop != 0) {//不是第一个元素就添加
					if (where == 1)
						stack[stackTop - 1]->left = newNode;
					else
						stack[stackTop - 1]->rigth = newNode;
				}
				else {
					tree = newNode;
				}
				break;
		}
	}
	printf("二叉树生成成功，输出如下\n");
	toGuangYi(tree);//将二叉树以广义表的形式输出
	printf("\n释放空间\n");
	myFree(tree);//释放内存
}



int main(int argc, char* args)
{
	GuangYiTo();

	return 0;
}