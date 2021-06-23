#define _CRT_SECURE_NO_WARNINGS 1  //vs编辑器认为scanf不安全 定义常量值即可规避编译器报错
#include <stdio.h>



//			辗转相除法求最大公因数
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d",&a,&b);
	while (c = a%b) {  // 如果a>b则余a b赋值给a即位置调换 然后就进行辗转相除法
		a = b;
		b = c;    //辗转相除法：大数/小数 = 商。。余数  然后用小数/余数 一直循环至余数为零则除数就是
				//最大公因数
	}
	printf("最大公约数为：%d",b);
	return 0;
}