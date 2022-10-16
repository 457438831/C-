
/*
	�ж���ȫ������
	��ȫ������ 1  
			 2   3
            4 5 6 7
	��������������

	�ж��Ƿ�����ȫ��������˼·�����ö��У�ֻҪ���ڵ�����Ͷ����еĽڵ㣬����ͬһ����������ȫ������
*/

#include<stdio.h>
#include <malloc.h>

typedef struct node {
	int data;
	struct node* lc, * rc;

}node,*bitptr;





//����������
bitptr createTree() {
	//ͷ�ڵ�
	bitptr bt = NULL;
	//����
	bitptr queque[10] = {NULL};
	int tou = 0, wei = 0;
	bitptr child;
	for (int i = 1; i < 8; i++)
	{
		child = (bitptr)malloc(sizeof(node));
		if (child == NULL)
			return NULL;
		//��ʼ������
		child->data = i;
		child->lc = NULL;
		child->rc = NULL;
		//��ͷָ�뱣��
		if (bt == NULL) {
			bt = child;
			//�����
			queque[wei] = child;
			wei = (wei + 1) % 10;
			continue;
		}
		//�����
		queque[wei] = child;
		wei = (wei + 1) % 10;
		while(queque[tou] != NULL){
			//�ӵ����
			if (queque[tou]->lc == NULL) {
				queque[tou]->lc = child;
				break;
			}
				
			//�ӵ��ұ�
			if (queque[tou]->rc == NULL) {
				queque[tou]->rc = child;
				break;
			}
			//������˾ͳ�����
			queque[tou] = NULL;
			tou = (tou + 1) % 10;
		}
	}
	return bt;
}



//��ʾ������
void display(bitptr b) {
	if (b == NULL)
		return;
	printf("%d ",b->data);
	display(b->lc);
	display(b->rc);
}

//���ٶ�����
void delNode(bitptr b) {
	if (b == NULL)
		return;
	delNode(b->lc);
	delNode(b->rc);
	free(b);
}
//�ж��Ƿ�����ȫ������  
int Comptree(bitptr t)
{
	if(t == NULL)
		return 1;
	bitptr queque[20] = {NULL};
	int index = 1,read = 0;
	queque[0] = t;
	while (true) {//�����нڵ�浽������
		
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
	
	//�ж�
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

//�����ת������
node* GuangYiTo() {
	node* stack[100];
	char read;//��ȡ�����ַ�
	node* newNode = NULL;//�����´����Ľڵ�
	int stackTop = 0;//stackջ��
	int where = 1;//����1��2��
	node* tree = NULL;
	int yesOrNo = 1;
	while (yesOrNo) {
		read = getc(stdin);

		switch (read) {
		case '(': //���½ڵ����ջ�� ������Ǹ�Ϊ��
			stack[stackTop++] = newNode;
			where = 1;
			break;

		case ','://����Ǹ�Ϊ��
			where = 2;
			break;

		case ')'://��ջ��Ԫ�س�ջ,����ջ����һ
			stack[--stackTop] = NULL;
			if (stackTop == 0)
				yesOrNo = 0;
			break;

		default://������϶������㣬Ĭ��Ϊ��������  ���������ݵĽڵ� �����ݷ�����ӵ�ջ��Ԫ�ص����λ��
			newNode = (node*)malloc(sizeof(node));
			if (newNode == NULL)
				return NULL;
			newNode->data = read;
			newNode->lc = NULL;
			newNode->rc = NULL;

			if (stackTop != 0) {//���ǵ�һ��Ԫ�ؾ����
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
//���㼶�ж�
int ceng(node* tree) {
	
	node* queue[20] = {NULL};
	int index = 1, read = 0;
	queue[0] = tree;
	int log = 0;//�����ǳ��ֿգ���ζ��֮�󶼲����пճ���
	while (true) {
		//���궼û�г��ֿ�
		if (queue[read] == NULL)
			break;
		//��
		if (queue[read]->lc != NULL) {
			if (log == 1)
				return 0;
			queue[index] = queue[read]->lc;
			++index;
		}else 
			log = 1;//���ֿվ��޸ı��
		
		//��
		if (queue[read]->rc != NULL) {
			if (log == 1)
				return 0;
			queue[index] = queue[read]->rc;
			++index;
		}else 
			log = 1;//���ֿվ��޸ı��
		
		queue[read] = NULL;
		++read;
	}
	return 1;
}

//int main(int argc, char* argv)
//{
//	//�̶�����
//	/*bitptr bt = createTree();
//	display(bt);
//	if (Comptree(bt))
//		printf("\n����ȫ������\n");
//	else
//		printf("\n������ȫ������\n");
//
//	delNode(bt);*/
//
//
//	//����
//	//node* tree = GuangYiTo();
//	//printf("���������ɳɹ�\n");
//	//display(tree);
//
//	//if (Comptree(tree))
//	//	printf("\n����ȫ������\n");
//	//else
//	//	printf("\n������ȫ������\n");
//
//	//printf("\n�ͷſռ�\n");
//	//delNode(tree);//�ͷ��ڴ�
//
//	//����������ж�
//	node* tree = GuangYiTo();
//	if (ceng(tree))
//		printf("\n����ȫ������\n");
//	else
//		printf("\n������ȫ������\n");
//	return 0;
//}

