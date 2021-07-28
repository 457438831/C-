

#include <iostream>
#include <string>

using namespace std;


struct student
{
	char name[20];
	int age;
	string aa;
};

void test01()
{

	struct student stu;
	stu = { "123",12 };
	cout << stu.name << "," << stu.age;
	stu = { "张三",25 };
	cout << stu.name << "," << stu.age;
	//结构体中数组不能直接struct.name = "张三",因为struct.name是数组首地址指针char* 
	//"张三"是一个常量地址const char* 
	memcpy(stu.name,"张四",sizeof("张四"));
	cout << stu.name;
}

void test02()
{
	class Mammal {
	public:
		Mammal(const string& species_name)
		{
			cout << species_name<<endl;
		};
	};
	class Cat : public Mammal
	{
	public:
		Cat() :Mammal("cat") {
			cout << "123";
		};
		
	};
	Cat cat;
	
}

//命名空间  类似于给空间内的所有变量都增加了一个bbq前缀  外部使用为 bbq::typeName
namespace bbq {

	namespace qqq {
		//可以嵌套
	}
	class add
	{
	public:
		add(int a ,int b)
		{
			cout << a - b;
		}
	};
}

int add(int a,int b)
{
	return a + b;
}

int main(int agr,char* agrv)
{
	test01();
	//test02();
	//命名空间
	//cout << add(5,1);//6
	//bbq::add(5,1);//4
	
	return 0;
}