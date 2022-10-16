/*=============================================================
	文件名称:模板类的使用
	作    者:小花儿
	编写时间:2021.10.27 15:24
	修改时间:
	内容简介:  类模板的使用
	1、自动类型推导
	2、显示类型指定
==============================================================*/


#include <iostream>

using namespace std;
template <typename T>
void Swap(T &a, T &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 20;
	int b = 10;
	//自动类型推导
	Swap(a, b);
	cout << a << "   " << b << endl;
	//显示类型指定
	Swap<int>(a, b);
	cout << a << "   " << b << endl;
}

int main()
{

	test();
	return 0;
}