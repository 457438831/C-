
/*

	������ʾ������

	A(B(,D),C(E,F(G)))  ��ʾ������
	������������ �����ڵ㣬������������ӵ�ָ��λ��

	���ܣ���������ʾ��������������������������ʾ��
*/


#include<stdio.h>
#include <malloc.h>

#define STACK_LENGTH 10

//�ڵ�
struct node {
	node *left,*rigth;
	char data;
};

//������ת�������
void toGuangYi(node* tree) {

	if (tree == NULL)
		return;
	printf("%c", tree->data);
	if (tree->left != NULL || tree->rigth != NULL) {
		printf("(");
		//��
		if (tree->left != NULL)
			toGuangYi(tree->left);

		//��
		if (tree->rigth != NULL)
		{
			printf(",");
			toGuangYi(tree->rigth);
		}
		printf(")");
	}
}

//�ͷ��ڴ�
void myFree(node* tree) {
	if (tree == NULL)
		return;
	if (tree->left != NULL)
		myFree(tree->left);
	if (tree->rigth != NULL)
		myFree(tree->rigth);
	free(tree);
}

//�����ת������
void GuangYiTo() {
	node* stack[STACK_LENGTH];
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
					return;
				newNode->data = read;
				newNode->left = NULL;
				newNode->rigth = NULL;

				if (stackTop != 0) {//���ǵ�һ��Ԫ�ؾ����
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
	printf("���������ɳɹ����������\n");
	toGuangYi(tree);//���������Թ�������ʽ���
	printf("\n�ͷſռ�\n");
	myFree(tree);//�ͷ��ڴ�
}



int main(int argc, char* args)
{
	GuangYiTo();

	return 0;
}