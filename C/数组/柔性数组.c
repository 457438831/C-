
#include <stdio.h>
#include <stdlib.h>


//		��������ʹ�ü�����
struct MyStruct
{
	int a;
	int arr[];//arr[0] *c99��׼   ������������   1 �ڴ������ʸ��� �����ڴ���Ƭ    2 ���ܸ��� �����洢�����ݶ�ȡ�ٶȸ���   3 �����ڴ��ͷŴ��� �����ٴ�����
};

int main()
{
 int i = 0;
	struct MyStruct* c = (struct MyStruct*)malloc(sizeof(struct MyStruct)+10*sizeof(int));//�ڶ�̬�ڴ漴���� ���ٿռ�   realloc(*p,size)���Ӷ�̬�ڴ棬�����ڴ���ʼλ�õ�ַ
	c->a = 10;
	
	for (i = 0; i < 10; i++)
	{
		c->arr[i] = i;
	}
	printf("%d \n",c->a);
	for (i = 0; i < 10; i++)
	{
		printf("%d ",c->arr[i]);
	}
	free(c);//�ͷſռ�
	c = NULL;//���ָ��
	return 0;
}