#include <stdio.h>




//				�ַ����Ⱥ���ʵ��(����)
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
	char arr[] = "������ɽ��4";
	int len = 0;
	len = my_strlen(arr);
	printf("�ܹ��У�%d ���ֽ�",len);
	return 0;
}
