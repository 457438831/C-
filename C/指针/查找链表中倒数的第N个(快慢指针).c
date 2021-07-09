#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//问题：查找链表中倒数的第N个

typedef struct listtab {//创建结构体   create struct
	int value;				//存放值
	struct listtab* next;	//存放下一位置指针
}Ltab;

Ltab* InitList()//初始化链表实现
{
	Ltab* l1 = (Ltab*)malloc(sizeof(Ltab)); //在堆内存中开辟空间
	Ltab* l2 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l3 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l4 = (Ltab*)malloc(sizeof(Ltab));
	Ltab* l5 = (Ltab*)malloc(sizeof(Ltab));

	l1->value = 1;  //将结构连接起来
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


void FindNum(const Ltab* head, int n)//实现查找倒数第几个  利用快慢指针
{
	assert(head);
	const Ltab* left = head;    //慢指针
	const Ltab* rigth = head;   //快指针
	while (rigth && n)
	{
		rigth = rigth->next;
		--n;
	}
	if (0 != n)
	{
		printf("元素超标 %d", n);
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
	Ltab* head = InitList();  //初始化链表
	FindNum(head, n); //查找倒数第几个

	return 0;
}

