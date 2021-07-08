#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//���⣺��ֵС��N�Ľڵ�ŵ��ڵ�ǰ

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

	l1->value = 5;  //���ṹ��������
	l1->next = l2;

	l2->value = 4;
	l2->next = l3;

	l3->value = 3;
	l3->next = l4;

	l4->value = 2;
	l4->next = l5;

	l5->value = 1;
	l5->next = NULL;
	return l1;
}

Ltab* FindSort(Ltab* head, const int num)//ʵ�ֲ��ҵ�����Nλ  ���õݹ�
{
	assert(head);
	Ltab* Small = (Ltab*)malloc(sizeof(Ltab));  //����һ���ڱ��������ӽ�С�ڵ�
	Ltab* Big = (Ltab*)malloc(sizeof(Ltab));	//����һ���ձ��������ӽϴ�ڵ�
	Ltab* wBig = Big;							//����ָ���������ѭ��ʹ��  
	Ltab* wSmall = Small;
	Ltab* rt = head;
	while (head)
	{
		if (head->value > num)					//����ýڵ��ֵ����num �����ýڵ����ӵ�wBig��
		{
			wBig->next = head;
			wBig = wBig->next;
		}
		else									//����ýڵ��ֵС��num �����ýڵ����ӵ�wSmall��
		{
			wSmall->next = head;
			wSmall = wSmall->next;
		}
		head = head->next;
	}
	wBig->next = NULL;
	wSmall->next = Big->next;
	rt = Small->next;
	free(Small);
	free(Big);
	Small = NULL;
	Big = NULL;
	return rt;
}

int main()
{
	int num = 3;
	Ltab* head = InitList();  //��ʼ������
	FindSort(head, num); //��������

	return 0;
}