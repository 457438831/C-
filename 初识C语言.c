


//            初识C语言
//	引头文件 <name.h>引用库函数    "name.h"引用自定义函数被
#include <stdio.h>
#include <string.h>

//	结构体创建
struct game {

	char name[20];
	short xue;
	short lan;
	int gongji;
};


int main() {

	// 结构体创建、初始化
	struct game xixi = {"123456",200,100,50};

	//结构体参数修改
	strcpy(xixi.name,"C语言"); //字符修改不能直接赋值
	xixi.xue = 200;
	xixi.lan = 100;
	xixi.gongji = 50;

	printf("名称：%s\n",xixi.name);
	printf("HP:%d\n",xixi.xue);
	printf("MP:%d\n",xixi.lan);
	printf("GJ:%d\n",xixi.gongji);

	// 结构体变量创建使用（指针实现）
	struct game* pd = &xixi;
	printf("名称：%s\n",pd->name);
	printf("HP:%d\n",pd->xue);
	printf("MP:%d\n",pd->lan);
	printf("GJ:%d\n",pd->gongji);
	return 0;
}

