/*
	��    �ܣ�c++�еĶ�̬  ��̬��̬  �Ͷ�̬��̬
	��    �ߣ�С����
	����ʱ�䣺2021.10.26 17:52
	�޸�ʱ�䣺
*/

#include <iostream>


using namespace std;
//������
class Animal
{
public:
	virtual void speak()//�麯�� ����virtual���Ǿ�̬��̬  ����ͬ�������ʵ�ֲ�ͬ������Ϊ��̬
	{
		cout << "animals are talking" << endl;
	}
};
//����
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
	Animal().speak();//���ý������ͷŸö���
	Do_Speak(sheep);
}


int main(int argc, char** argv)
{
	test();
	return 0;
}

