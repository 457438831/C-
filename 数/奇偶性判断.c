#include <stdio.h>


//				奇偶性判断
int moer(int a) {
	return a % 2;
}

int main() {
	//while循环 实现
		int i = 1;
	while (100 >= i) {
		if (0 != i % 2)
			printf("奇数: %d\n", i);
		else {
			printf("偶数:%d\n", i);
		}
		i++;
	}
	//for 循环 自定义函数  实现
	for (int i = 1; i <= 100; i++)
	{
		if (0 != moer(i)) {
			printf("奇数：%d\n",i);
		}
		else {
			printf("偶数:%d\n",i);
		}
	}
		return 0;
}