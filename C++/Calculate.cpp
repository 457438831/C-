/*=============================================================
	文件名称:抽象多态
	作    者:小花儿
	编写时间:2021.10.26 20:24
	修改时间:
	内容简介:抽象多态实现计算器的加减乘除
==============================================================*/

#include <iostream>

using namespace std;
//创建一个base类
class AbstrateCalculate
{
public:
	virtual int getResult() { return 0; };//纯虚函数  子类必须实现否则无法实例化 
	int one, two;
};
//加
class Add : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one + two;
	}
};
//减
class Sub : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one - two;
	}
};
//乘
class Mul : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one * two;
	}
};
//除
class Div : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one / two;
	}
};



void test()
{
	
	Add add;
	add.one = 10;
	add.two = 10;
	cout << add.getResult() << endl;

	Sub sub;
	sub.one = 10;
	sub.two = 10;
	cout << sub.getResult() << endl;

	Mul mul;
	mul.one = 10;
	mul.two = 10;
	cout << mul.getResult() << endl;

	Div div;
	div.one = 10;
	div.two = 10;
	cout << div.getResult() << endl;
}

int main(int argc,char** argv)
{
	test();

	return 0;
}