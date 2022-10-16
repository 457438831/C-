
/*
	判断完全二叉树
	完全二叉树 1  
			 2   3
            4 5 6 7
	必须是有序排列

	判断是否是完全二叉树的思路，利用队列，只要根节点的左侧和队列中的节点，不是同一个，则不是完全二叉树
*/

#include<stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* lc, * rc;

}node,*bitptr;





//创建二叉树
bitptr createTree() {
	//头节点
	bitptr bt = NULL;
	//队列
	bitptr queque[10] = {NULL};
	int tou = 0, wei = 0;
	bitptr child;
	for (int i = 1; i < 8; i++)
	{
		child = (bitptr)malloc(sizeof(node));
		if (child == NULL)
			return NULL;
		//初始化数据
		child->data = i;
		child->lc = NULL;
		child->rc = NULL;
		//将头指针保存
		if (bt == NULL) {
			bt = child;
			//入队列
			queque[wei] = child;
			wei = (wei + 1) % 10;
			continue;
		}
		//入队列
		queque[wei] = child;
		wei = (wei + 1) % 10;
		while(queque[tou] != NULL){
			//加到左边
			if (queque[tou]->lc == NULL) {
				queque[tou]->lc = child;
				break;
			}
				
			//加到右边
			if (queque[tou]->rc == NULL) {
				queque[tou]->rc = child;
				break;
			}
			//都添加了就出队列
			queque[tou] = NULL;
			tou = (tou + 1) % 10;
		}
	}
	return bt;
}



//显示二叉树
void display(bitptr b) {
	if (b == NULL)
		return;
	printf("%d ",b->data);
	display(b->lc);
	display(b->rc);
}

//销毁二叉树
void delNode(bitptr b) {
	if (b == NULL)
		return;
	delNode(b->lc);
	delNode(b->rc);
	free(b);
}
//判断是否是完全二叉树  
int Comptree(bitptr t)
{
	if(t == NULL)
		return 1;
	bitptr queque[20] = {NULL};
	int index = 1,read = 0;
	queque[0] = t;
	while (true) {//将所有节点存到队列中
		
		if (queque[read]->lc != NULL) {
			queque[index] = queque[read]->lc;
			++index;
		}
		if (queque[read]->rc != NULL) {
			queque[index] = queque[read]->rc;
			++index;
		}

		if (queque[read]->lc == NULL && queque[read]->rc == NULL && queque[read + 1] == NULL)
			break;
		++read;
	}
	
	//判断
	int left, right;
	for (int i = 0; i < 20; i++)
	{
		if (queque[i] == NULL)
			break;
		left = i * 2 + 1;
		right = i * 2 + 2;
		if (queque[i]->lc != queque[left] || queque[i]->rc != queque[right])
			return 0;
	}
	return 1;
}

//广义表转二叉树
node* GuangYiTo() {
	node* stack[100];
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
				return NULL;
			newNode->data = read;
			newNode->lc = NULL;
			newNode->rc = NULL;

			if (stackTop != 0) {//不是第一个元素就添加
				if (where == 1)
					stack[stackTop - 1]->lc = newNode;
				else
					stack[stackTop - 1]->rc = newNode;
			}
			else {
				tree = newNode;
			}
			break;
		}
	}
	return tree;
}
//按层级判断
int ceng(node* tree) {
	
	node* queue[20] = {NULL};
	int index = 1, read = 0;
	queue[0] = tree;
	int log = 0;//用与标记出现空，意味着之后都不能有空出现
	while (true) {
		//读完都没有出现空
		if (queue[read] == NULL)
			break;
		//左
		if (queue[read]->lc != NULL) {
			if (log == 1)
				return 0;
			queue[index] = queue[read]->lc;
			++index;
		}else 
			log = 1;//出现空就修改标记
		
		//右
		if (queue[read]->rc != NULL) {
			if (log == 1)
				return 0;
			queue[index] = queue[read]->rc;
			++index;
		}else 
			log = 1;//出现空就修改标记
		
		queue[read] = NULL;
		++read;
	}
	return 1;
}

//int main(int argc, char* argv)
//{
//	//固定创建
//	/*bitptr bt = createTree();
//	display(bt);
//	if (Comptree(bt))
//		printf("\n是完全二叉树\n");
//	else
//		printf("\n不是完全二叉树\n");
//
//	delNode(bt);*/
//
//
//	//灵活创建
//	//node* tree = GuangYiTo();
//	//printf("二叉树生成成功\n");
//	//display(tree);
//
//	//if (Comptree(tree))
//	//	printf("\n是完全二叉树\n");
//	//else
//	//	printf("\n不是完全二叉树\n");
//
//	//printf("\n释放空间\n");
//	//delNode(tree);//释放内存
//
//	//按层读数据判断
//	node* tree = GuangYiTo();
//	if (ceng(tree))
//		printf("\n是完全二叉树\n");
//	else
//		printf("\n不是完全二叉树\n");
//	return 0;
//}

