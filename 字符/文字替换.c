#include <stdio.h>

//数组文字替换
int main() {
	char arr1[] = {"wellcome to my home !"};
	char arr2[] = {"#####################"};
	int left = 0;//左下标
	int rigth = strlen(arr1)-1;//右下标
	while (left<=rigth) {
		arr2[left] = arr1[left];
		arr2[rigth] = arr1[rigth];
		printf("%s\n", arr2);
		left++;
		rigth--;
	}
	
	return 0;
}
