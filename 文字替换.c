#include <stdio.h>

//���������滻
int main() {
	char arr1[] = {"wellcome to my home !"};
	char arr2[] = {"#####################"};
	int left = 0;//���±�
	int rigth = strlen(arr1)-1;//���±�
	while (left<=rigth) {
		arr2[left] = arr1[left];
		arr2[rigth] = arr1[rigth];
		printf("%s\n", arr2);
		left++;
		rigth--;
	}
	
	return 0;
}
