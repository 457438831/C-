#include <iostream>//����IO�ļ�

using namespace std;  //ʹ�������ܵ�

void table()//��������ŵ�main����֮�� ����Ҫ����   ��Ϊϵͳ���ļ��Ǵ�������
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < i + 1; j++)
		{
			cout << j << "*" << i << "=" << i * j << '\t';
		}
		cout << '\n';
	}
}

int main()
{
	table();//��ӡ�˷��ھ���
}

