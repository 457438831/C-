#include <stdio.h>


//				自定义函数（求字符串长度）方法： 末指针地址  减  始指针地址 = 中间元素
int my_strlen(char* arr)
{
	char* start = arr;
	char* end = arr;
	while (*end !='\0')
	{
		end++;
	}
	return end - start;
}

int main()
{
	char arr[] = {"白日依山尽,黄河入海流,欲穷千里目,更上一层楼"};
	int len = 0;
	len = my_strlen(arr);
	printf("%d",len);

	return 0;
}