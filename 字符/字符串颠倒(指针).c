
#include <stdio.h>
//			字符串颠倒（创建指针方法）

//计算字符串长度
int my_strlen(char* arr)
{
	int count = 0;
	while (*arr)
	{
		count++;
		arr++;
	}
	return count;
}

//反转字符串
void reverse_string(char* arr)
{
	int len = my_strlen(arr);
	char* left = arr;
	char* rigth = arr + len - 1;
	while (left < rigth)
	{
		char tmp = *left;
		*left = *rigth;
		*rigth = tmp;
		left++;
		rigth--;
	}
}

int main()
{
	char arr[100] = "hello word";
	reverse_string(arr);
	printf("%s",arr);
	return 0;
}