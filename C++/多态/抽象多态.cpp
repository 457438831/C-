
/*=============================================================
	�ļ�����:�����̬
	��    ��:С����
	��дʱ��:2021.10.26 20:24
	�޸�ʱ��:
	���ݼ��:ʹ���麯���Ͷ�̬   �������������� ������ø������
	�麯�� ��ʵ�ֿɲ�ʵ�� �����ΪĬ�Ϻ���  
	���麯���� functionName() = 0;
	class Ĭ�����г�ԱΪ private
	struct Ĭ�����г�ԱΪ public
==============================================================*/

#include <iostream>

using namespace std;
//����һ��base��
class AbstrateBase
{
public:
	//��ˮ
	virtual void Boil() = 0;//���麯��  ��Ҫ����ʵ�� ��������Ҳ����Ϊ������
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//��������
	virtual void PutSomething() = 0;

	//��
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
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�ӵ����" << endl;
	}
};
//tea class
class Tea : public AbstrateBase
{
public:
	virtual void Boil()
	{
		cout << "��ˮ" << endl;
	}
	virtual void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup()
	{
		cout << "���뱭��" << endl;
	}
	virtual void PutSomething()
	{
		cout << "�ӵ������" << endl;
	}
};


void FatherCallSon(AbstrateBase &absb)
{
	absb.Drink();
}

void test()
{
	//��������
	Coffee coffee;
	coffee.Drink();
	Tea tea;
	tea.Drink();
	cout << "--------------------------------" << endl;
	//��������������
	FatherCallSon(coffee);
	FatherCallSon(tea);


}

int main(int argc, char** argv)
{
	test();
	return 0;
}