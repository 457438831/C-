
/*=============================================================
	文件名称:抽象多态
	作    者:小花儿
	编写时间:2021.10.26 20:24
	修改时间:
	内容简介:使用虚函数和多态   父类调用子类对象 子类调用父类对象
	虚函数 可实现可不实现 可理解为默认函数  
	纯虚函数即 functionName() = 0;
	class 默认所有成员为 private
	struct 默认所有成员为 public
==============================================================*/

#include <iostream>

using namespace std;
//创建一个base类
class AbstrateBase
{
public:
	//煮水
	virtual void Boil() = 0;//纯虚函数  需要子类实现 否则子类也将视为纯虚类
	//冲泡
	virtual void Brew() = 0;
	//倒入杯子
	virtual void PourInCup() = 0;
	//加入佐料
	virtual void PutSomething() = 0;

	//喝
	virtual void Drink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};
//coffee class
class Coffee : public AbstrateBase
{
public:
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯子" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加点儿糖" << endl;
	}
};
//tea class
class Tea : public AbstrateBase
{
public:
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯子" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加点儿柠檬" << endl;
	}
};


void FatherCallSon(AbstrateBase &absb)
{
	absb.Drink();
}

void test()
{
	//正常调用
	Coffee coffee;
	coffee.Drink();
	Tea tea;
	tea.Drink();
	cout << "--------------------------------" << endl;
	//父类调用子类对象
	FatherCallSon(coffee);
	FatherCallSon(tea);


}

int main(int argc, char** argv)
{
	test();
	return 0;
}