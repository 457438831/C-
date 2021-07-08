#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//���⣺�ж������ǲ��ǻ��Ľṹ�� 12321
//˼·�����ÿ���ָ��   ������ǰ�벿������ ���벿�ֱȽ�
typedef struct listtab {//�����ṹ��   create struct
	int value;				//���ֵ
	struct listtab* next;	//�����һλ��ָ��
}Ltab;

Ltab* InitList()//��ʼ������ʵ��
{
	Ltab* l1 = (Ltab*)malloc(sizeof(Ltab)); //�ڶ��ڴ��п��ٿռ�
	Ltab* l2 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l3 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l4 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l5 = (Ltab*)malloc(sizeof(Ltab));

	l1->value = 1;  //���ṹ��������
	l1->next = l2;

	l2->value = 2;
	l2->next = l3;

	l3->value = 3;
	l3->next = l4;

	l4->value = 2;
	l4->next = l5;

	l5->value = 1;
	l5->next = NULL;
	return l1;
}

int Decide(Ltab* head)//�ж��Ƿ�Ϊ����
{
	assert(head);
	Ltab* left = head;		//��ָ��
	Ltab* right = head;		//��ָ��
	Ltab* pChange = NULL;	//ָ���������ָ��  ��Ҫͷ���ָ��
	Ltab* p = NULL;			//���ڴ洢��һ���ڵ��ֵ  �������ַβ�嵽pChange
	if (head->next == NULL) // �������ֻ��һ���ڵ�Ļ�ֱ�ӷ���0
	{
		return 0;
	}
	while (right && right->next)//��������������
	{
		pChange = left;		//��ʼ������ָ��
		left = left->next;	//��ָ�뿪ʼ�ƶ�   1һ���ڵ�
		right = right->next->next;	//��ָ�뿪ʼ�ƶ�  2���ڵ�
		pChange->next = p;	//��Ҫ�洢����һ���ڵ�β�嵽���ڵĽڵ�   ��Ϊ�ǵ�һ�����Բ���NULL
		p = pChange;		//���漴��β��ĵ�ַ
	}

	if (right == NULL) //ż����  �м�������һ�� ���Ըպò������������ȵ�����
	{
		while (pChange)
		{
			if (pChange->value != left->value)
			{
				return 0;
			}
			pChange = pChange->next;
			left = left->next;
		}
		return 1;
	}
	else			//������   �м�û��һ���ļ�left���pChange��һ���м�Ԫ�� ����ȡleft->next��ֵ���бȽ�
	{
		left = left->next;
		while (pChange)
		{
			if (pChange->value != left->value)
			{
				return 0;
			}
			pChange = pChange->next;
			left = left->next;
		}
		return 1;
	}
}

int main()
{

	Ltab* head = InitList();  //��ʼ������
	if (Decide(head))
		printf("�ǻ���"); //�ж��Ƿ�Ϊ����   0�����   1���
	else
		printf("���ǻ���");
	return 0;
}

