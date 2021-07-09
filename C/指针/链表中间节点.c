#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//���⣺��������м��ַ�������λ����������������һ��
//˼·�����õݹ�����   ���β��ҵ�ָ��Ϊ�� ������м�ֵ  Ȼ�����õݹ������жϸ�λ���Ƿ����м�ֵ

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

/*
	�����м�ڵ� ����������м�ڵ㷵�صڶ���
	������ͷ��ַ����¼����λ�ã���¼�м�ֵ��
*/
void FindMid(Ltab* head, int count, int* mid)//ʵ�ֲ����м�ֵ
{
	assert(head && mid);
	count++;
	if (head->next)
	{
		FindMid(head->next, count, mid);
	}
	else
	{
		*mid = count / 2 + 1;
	}
	if (*mid == count)
	{
		printf("��ַ��%p  ֵΪ��%d\n", head, head->value);
	}
	free(head);			//�ͷ��ڴ沢����ֵ
	head = NULL;
}

int main()
{
	int count = 0;
	int mid = 0;
	Ltab* head = InitList();  //��ʼ������
	FindMid(head, count, &mid); //�����м�ֵ

	return 0;
}

