

#include <stdio.h>
#include <string.h>
#include <assert.h>

//				�Զ���ʵ��ð�ݿ⺯��(�ṹ������)

struct Stu {   //�����ṹ��
	char name[20];
	int age;
};

void jiaohuan(char* a, char* b,int witch)//�ṹ�彻��
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
//	�Զ���ð�����򷨣��������ͣ���Ҫ�����Դָ�룬����ĸ�����ÿ��Ԫ����ռ�ֽڣ��ж���������ָ�룩
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
				//����
			}
		}
	}
}

int panduan(const void* in,const void* to)//���ֱȽ�
{
	//�����㽻��
	//�����㲻����
	//С���㲻����
	//return *(int*)in - *(int*)to;
	assert(in&&to);
	return strcmp((*(struct Stu*)in).name , (*(struct Stu*)to).name);  //strcmp  in>to ����>0  in=to ����=0 in<to ����<0
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
	int len = sizeof(arr) / sizeof(arr[0]);  //��������Ԫ�ظ���
	int witch = sizeof(arr[0]);				 //���㵥��Ԫ�ش�С
	//�Զ��� Qsort
	my_maopao(arr,len,witch,panduan);
	print(arr,len);  // ��ӡ
}

int main()
{
	test();
	return 0;
}