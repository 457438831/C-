#include <stdio.h>


//				��ż���ж�
int moer(int a) {
	return a % 2;
}

int main() {
	//whileѭ�� ʵ��
		int i = 1;
	while (100 >= i) {
		if (0 != i % 2)
			printf("����: %d\n", i);
		else {
			printf("ż��:%d\n", i);
		}
		i++;
	}
	//for ѭ�� �Զ��庯��  ʵ��
	for (int i = 1; i <= 100; i++)
	{
		if (0 != moer(i)) {
			printf("������%d\n",i);
		}
		else {
			printf("ż��:%d\n",i);
		}
	}
		return 0;
}