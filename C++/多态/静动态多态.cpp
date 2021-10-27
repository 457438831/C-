/*
	功    能：c++中的多态  静态多态  和动态多态
	作    者：小花儿
	创建时间：2021.10.26 17:52
	修改时间：
*/

#include <iostream>


using namespace std;
//动物类
class Animal
{
public:
	virtual void speak()//虚函数 不加virtual则是静态多态  ：及同种类可以实现不同方法即为多态
	{
		cout << "animals are talking" << endl;
	}
};
//羊类
class Sheep : public Animal
{
public:
	void speak()
	{
		cout << "sheeps are talking" << endl;
	}
};

void Do_Speak(Animal& animal)
{
	 animal.speak();
}

void test()
{
	Sheep sheep;
	sheep.speak();
	Animal().speak();//调用结束就释放该对象
	Do_Speak(sheep);
}


int main(int argc, char** argv)
{
	test();
	return 0;
}

