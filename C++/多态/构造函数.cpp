/*=============================================================
	文件名称:虚构函数、纯虚构函数
	作    者:小花儿
	编写时间:2021.10.27 10:21
	修改时间:
	内容简介:

	使用父类指向子类引用 执行析构时不会析构子类对象
	需要将父类的析构函数 修改为虚析构函数即 virtual ~FunctionName();
	纯虚析构函数 virtual ~FunctionName() = 0;
	区别：纯虚析构函数必须要有定义 且该类不能实例化 
	虚函数
==============================================================*/

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal in Construator,do nathing" << endl;
	}
	virtual ~Animal()
	{
		cout << "Animal in Destructor,do nathing" << endl;
	
	}
	virtual void Speak() = 0;
	
};

class Cat : public Animal
{
public:
	Cat()
	{
		cout << "Cat in constructor,New String" << endl;
		Name = new string("Tom");
	}
	~Cat()
	{
		cout << "Cat in destructor";
		if (NULL != Name)
		{
			delete Name;
			cout << ", Delete NamePointer" << endl;
		}
		else { cout << endl; }
	}

	void Speak()
	{
		cout <<*Name<< "Cat in Sepak" << endl;
	}
	string *Name;
};


void test()
{
	//不采用虚析构也能正常执行子类析构
	Cat cat;
	Animal* animal = &cat;
	animal->Speak();


	//采用虚析构才能正常执行子类析构
	/*Animal* animal = new Cat;
	animal->Speak();
	delete animal;*/

}

int main(int argc, char** argv)
{
	test();

	return 0;
}




