/*=============================================================
	�ļ�����:�鹹���������鹹����
	��    ��:С����
	��дʱ��:2021.10.27 10:21
	�޸�ʱ��:
	���ݼ��:

	ʹ�ø���ָ���������� ִ������ʱ���������������
	��Ҫ��������������� �޸�Ϊ������������ virtual ~FunctionName();
	������������ virtual ~FunctionName() = 0;
	���𣺴���������������Ҫ�ж��� �Ҹ��಻��ʵ���� 
	�麯��
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
	//������������Ҳ������ִ����������
	Cat cat;
	Animal* animal = &cat;
	animal->Speak();


	//������������������ִ����������
	/*Animal* animal = new Cat;
	animal->Speak();
	delete animal;*/

}

int main(int argc, char** argv)
{
	test();

	return 0;
}




