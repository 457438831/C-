#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <exception>
using namespace std;

class myException
{
public:
	myException(const char* erro) 
	{
		erroCode = new char[strlen(erro)+1];
		strcpy(erroCode,erro);
	}

	char* what()
	{
		return erroCode;
	}

private:
	char* erroCode;
};


int add(int a,int b)
{
	if (b == 0)
		throw myException("´íÎó");
	return a + b;
}

void test01()
{
	try 
	{
		int sum = add(5,9);
		cout << sum;
	}
	catch(myException erro)
	{
		cout << erro.what();
	}
}

int main()
{
	test01();  //Òì³£´¦Àí

	return 0;
}