/*=============================================================
	�ļ�����:ģ�����ʹ��
	��    ��:С����
	��дʱ��:2021.10.27 15:24
	�޸�ʱ��:
	���ݼ��:  ��ģ���ʹ��
	1���Զ������Ƶ�
	2����ʾ����ָ��
==============================================================*/


#include <iostream>

using namespace std;
template <typename T>
void Swap(T &a, T &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 20;
	int b = 10;
	//�Զ������Ƶ�
	Swap(a, b);
	cout << a << "   " << b << endl;
	//��ʾ����ָ��
	Swap<int>(a, b);
	cout << a << "   " << b << endl;
}

int main()
{

	test();
	return 0;
}