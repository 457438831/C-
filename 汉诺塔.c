#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <windows.h>



//				汉诺塔实现
// 分为三部
//    移动N-1个 从x经由z放到y上
//	  移动X上剩下的一个到y上
//    将y上的n-1个经由x放到y上
void move(char c1, char c2) {
	printf("%c -> %c\n", c1, c2);
}

void hanoi(int n,char x,char y ,char z) {
	if (n == 1) {
		move(x,z);
	}
	else {
		hanoi(n-1,x,z,y);
		move(x,z);                  //汉诺塔函数
		hanoi(n-1,y,x,z);
	}
}

int main() {
	int n = 0;
	int yes= 0;
jixu:
	system("cls");
	printf("please input n: ");
	scanf("%d",&n);
	hanoi(n,'a','b','c');
	printf("是否继续？1:yes  0:no \n->");
	scanf("%d", &yes);
	if (yes == 1) {
		goto jixu;
	}
	return 0;
}
