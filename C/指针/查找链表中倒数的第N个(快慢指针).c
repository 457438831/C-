#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//���⣺���������е����ĵ�N��

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

	l4->value = 4;
	l4->next = l5;

	l5->value = 5;
	l5->next = NULL;
	return l1;
}


void FindNum(const Ltab* head, int n)//ʵ�ֲ��ҵ����ڼ���  ���ÿ���ָ��
{
	assert(head);
	const Ltab* left = head;    //��ָ��
	const Ltab* rigth = head;   //��ָ��
	while (rigth && n)
	{
		rigth = rigth->next;
		--n;
	}
	if (0 != n)
	{
		printf("Ԫ�س��� %d", n);
		return;
	}
	while (rigth)
	{
		left = left->next;
		rigth = rigth->next;
	}
	printf("adress: %p  num:%d", left, left->value);
}

int main()
{
	int n = 2;
	Ltab* head = InitList();  //��ʼ������
	FindNum(head, n); //���ҵ����ڼ���

	return 0;
}

