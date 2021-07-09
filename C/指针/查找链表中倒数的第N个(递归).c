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


void FindNum(const Ltab* head, int* num, int count, const int n)//实现查找倒数第N位  利用递归
{
	assert(head);
	count++;
	if (head->next)
	{
		FindNum(head->next, num, count, n);
	}
	else
	{
		if (n > count)
		{
			printf("大于目标长度%d", n - count);
			return;
		}
		*num = count - n + 1;
	}
	if (count == *num)
		printf("adress: %p  num: %d", head, head->value);
}

int main()
{
	int num = 0;
	int count = 0;
	int n = 5;
	Ltab* head = InitList();  //初始化链表
	FindNum(head, &num, count, n); //查找倒数第N个

	return 0;
}

