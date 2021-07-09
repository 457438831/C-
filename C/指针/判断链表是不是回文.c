#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//问题：判断链表是不是回文结构即 12321
//思路：利用快慢指针   将链表前半部分逆置 与后半部分比较
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

	l4->value = 2;
	l4->next = l5;

	l5->value = 1;
	l5->next = NULL;
	return l1;
}

int Decide(Ltab* head)//判断是否为回文
{
	assert(head);
	Ltab* left = head;		//慢指针
	Ltab* right = head;		//快指针
	Ltab* pChange = NULL;	//指向操作数的指针  即要头插的指针
	Ltab* p = NULL;			//用于存储上一个节点的值  讲这个地址尾插到pChange
	if (head->next == NULL) // 如果链表只有一个节点的话直接返回0
	{
		return 0;
	}
	while (right && right->next)//将链表拆成两部分
	{
		pChange = left;		//初始化操作指针
		left = left->next;	//左指针开始移动   1一个节点
		right = right->next->next;	//右指针开始移动  2个节点
		pChange->next = p;	//将要存储的上一个节点尾插到现在的节点   因为是第一个所以插入NULL
		p = pChange;		//保存即将尾插的地址
	}

	if (right == NULL) //偶数个  中间有两个一样 所以刚好拆成两个长短相等的链表
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
	else			//奇数个   中间没有一样的即left会比pChange多一个中间元素 所以取left->next的值进行比较
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

	Ltab* head = InitList();  //初始化链表
	if (Decide(head))
		printf("是回文"); //判断是否为回文   0不相等   1相等
	else
		printf("不是回文");
	return 0;
}

