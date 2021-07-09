

#include <stdio.h>
#include <string.h>
#include <assert.h>

//				自定义实现冒泡库函数(结构体排序)

struct Stu {   //创建结构体
	char name[20];
	int age;
};

void jiaohuan(char* a, char* b,int witch)//结构体交换
{
	assert(a && b);
	int i = 0;
	for (i = 0; i < witch; i++)
	{
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}
//	自定义冒泡排序法（参数类型：需要排序的源指针，排序的个数，每个元素所占字节，判断条件函数指针）
void my_maopao(void* arr,const int len,const int witch,int (*cmp)(void* ,void*))
{
	assert(arr&&len&&witch&&cmp);
	int i = 0;
	int b = 0;
	for (i = 0; i < len -1; i++)
	{
		for (b = 0; b < len -1 - i; b++)
		{
			if (cmp(((char*)arr) + b * witch, ((char*)arr) + b * witch + witch) > 0)
			{
				jiaohuan((char*)arr + b * witch,(char*)arr + b * witch + witch,witch);
				//调换
			}
		}
	}
}

int panduan(const void* in,const void* to)//名字比较
{
	//大于零交换
	//等于零不交换
	//小于零不交换
	//return *(int*)in - *(int*)to;
	assert(in&&to);
	return strcmp((*(struct Stu*)in).name , (*(struct Stu*)to).name);  //strcmp  in>to 返回>0  in=to 返回=0 in<to 返回<0
}

void print(const struct Stu* arr,const int len)
{
	assert(arr);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%s ",(*arr).name);
		printf("%d \n", (*arr).age);
		arr++;
	}
}

void test() 
{
	struct Stu arr[] = { {"zhangsan",25} ,{"lisi",45} ,{"wangwu",10}};
	//int arr[] = {0,1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr) / sizeof(arr[0]);  //计算数组元素个数
	int witch = sizeof(arr[0]);				 //计算单个元素大小
	//自定义 Qsort
	my_maopao(arr,len,witch,panduan);
	print(arr,len);  // 打印
}

int main()
{
	test();
	return 0;
}