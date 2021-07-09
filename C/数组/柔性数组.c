
#include <stdio.h>
#include <stdlib.h>


//		柔性数组使用及介绍
struct MyStruct
{
	int a;
	int arr[];//arr[0] *c99标准   柔性数组优势   1 内存利用率更高 减少内存碎片    2 性能更优 连续存储的数据读取速度更快   3 减少内存释放次数 即减少错误几率
};

int main()
{
 int i = 0;
	struct MyStruct* c = (struct MyStruct*)malloc(sizeof(struct MyStruct)+10*sizeof(int));//在动态内存即堆区 开辟空间   realloc(*p,size)增加动态内存，返回内存起始位置地址
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
	free(c);//释放空间
	c = NULL;//清空指针
	return 0;
}