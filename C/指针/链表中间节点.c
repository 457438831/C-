#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//问题：输出链表中间地址，如果中位数有两个则输出最后一个
//思路：利用递归属性   依次查找到指针为空 即算出中间值  然后利用递归特性判断该位置是否是中间值

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

/*
	查找中间节点 如果有两个中间节点返回第二个
	（链表头地址，记录链表位置，记录中间值）
*/
void FindMid(Ltab* head, int count, int* mid)//实现查找中间值
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
		printf("地址：%p  值为：%d\n", head, head->value);
	}
	free(head);			//释放内存并赋空值
	head = NULL;
}

int main()
{
	int count = 0;
	int mid = 0;
	Ltab* head = InitList();  //初始化链表
	FindMid(head, count, &mid); //查找中间值

	return 0;
}

