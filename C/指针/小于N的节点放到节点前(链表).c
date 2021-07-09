#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//问题：将值小于N的节点放到节点前

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

	l1->value = 5;  //将结构连接起来
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

Ltab* FindSort(Ltab* head, const int num)//实现查找倒数第N位  利用递归
{
	assert(head);
	Ltab* Small = (Ltab*)malloc(sizeof(Ltab));  //创建一个哨兵用于链接较小节点
	Ltab* Big = (Ltab*)malloc(sizeof(Ltab));	//创建一个烧饼用于链接较大节点
	Ltab* wBig = Big;							//创建指针变量用于循环使用  
	Ltab* wSmall = Small;
	Ltab* rt = head;
	while (head)
	{
		if (head->value > num)					//如果该节点的值大于num 即将该节点链接到wBig后
		{
			wBig->next = head;
			wBig = wBig->next;
		}
		else									//如果该节点的值小于num 即将该节点链接到wSmall后
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
	Ltab* head = InitList();  //初始化链表
	FindSort(head, num); //查找排序

	return 0;
}