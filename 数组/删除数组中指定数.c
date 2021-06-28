#include <stdio.h>
#include <assert.h>


//删除数组中指定数
void delnum(int* arr,const int num,int* size)
{
	assert(arr&&size);
	int* start = arr;//创建一个指针用于指向不为num的数
	int cont = *size;
	int i = 0;
	for (i = 0; i < cont; i++)
	{
		if (arr[i] != num)//如果不等于指定数则把arr值给start  将相同数往后移
		{
			*start = arr[i];
			start += 1;
		}
		else if (arr[i] == num)//如果值为num则size-1且去下一个数
		{
			*size -=1;
		}
	}
	while (1)
	{
		if (cont > *size)//判断有多少个相同数   将在最后的n格相同数置为0
		{
			arr[(cont - 1)] = 0;
			cont--;
		}
		else
		{
			break;
		}
	}
}

void print(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
}

int main()
{
	int num = 10;//指定数
	int arr[] = {0,10,10,10,10,2,10,10,10,10,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	delnum(arr,num,&size);//删除数组中指定数  并修改数组
	print(arr,size);//打印
	return 0;
}