
#include <stdio.h>

//    字符数组反转（递归法）


//自定义字符长度函数
int my_string(char arr[])
{
	char* p = arr;
	int count = 0;
	while (*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}

//反转字符串
void reverse_string(char arr[])
{
	char tmp = arr[0];  //将第一个元素给tmp
	int sz = my_string(arr);
	arr[0] = arr[sz - 1];//  将最后一个元素拿到第一个，然后将‘\0’给最后一个元素
	arr[sz - 1] = '\0';
	if (sz - 1 > 1) {//    因为'\0'给最后一个元素，所以数量减一
		reverse_string(arr + 1);//  指针向后移动一位 并调用自身
	}
	arr[sz - 1] = tmp;
}

void print(char arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
}

int main()
{
	char arr[] = {"abcdefg"};
	int sz = my_string(arr);//获取字符长度  
	reverse_string(arr);//反转函数
	print(arr,sz);
	printf(" 共有：%d个字符", sz);
	return 0;
}