#include <stdio.h>




//				字符长度函数实现(变量)
int my_strlen(char* arr) {
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}

int main() {
	char arr[] = "白日依山尽4";
	int len = 0;
	len = my_strlen(arr);
	printf("总共有：%d 个字节",len);
	return 0;
}
