

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
	stu = { "����",25 };
	cout << stu.name << "," << stu.age;
	//�ṹ�������鲻��ֱ��struct.name = "����",��Ϊstruct.name�������׵�ַָ��char* 
	//"����"��һ��������ַconst char* 
	memcpy(stu.name,"����",sizeof("����"));
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

//�����ռ�  �����ڸ��ռ��ڵ����б�����������һ��bbqǰ׺  �ⲿʹ��Ϊ bbq::typeName
namespace bbq {

	namespace qqq {
		//����Ƕ��
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
	//�����ռ�
	//cout << add(5,1);//6
	//bbq::add(5,1);//4
	
	return 0;
}