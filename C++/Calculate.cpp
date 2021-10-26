/*=============================================================
	�ļ�����:�����̬
	��    ��:С����
	��дʱ��:2021.10.26 20:24
	�޸�ʱ��:
	���ݼ��:�����̬ʵ�ּ������ļӼ��˳�
==============================================================*/

#include <iostream>

using namespace std;
//����һ��base��
class AbstrateCalculate
{
public:
	virtual int getResult() { return 0; };//���麯��  �������ʵ�ַ����޷�ʵ���� 
	int one, two;
};
//��
class Add : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one + two;
	}
};
//��
class Sub : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one - two;
	}
};
//��
class Mul : public AbstrateCalculate
{
public:
	int getResult()
	{
		return one * two;
	}
};
//��
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