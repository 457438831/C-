/*=============================================================
	�ļ�����:�ļ�����
	��    ��:С����
	��дʱ��:2021.10.27 13:56
	�޸�ʱ��:
	���ݼ��:
	 ���ö�̬ ģ��������װ
==============================================================*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void ReadFile()
{
	ifstream ifs;
	ifs.open("test.txt",ios::in);
	//check file open true or false
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	char buff[1024] = { 0 };
	//��һ�� 
	/*
	while (ifs.getline(buff, sizeof(buff)))
		cout << buff << endl;;*/

	//�ڶ���
	/*while (ifs >> buff)     ����������ǰ��ո��з��ַ�
		cout << buff << endl;*/
	//������
	/*string str;
	while (getline(ifs, str))
		cout << str << endl;*/
	//������
	char c;
	while ((c = ifs.get()) !=EOF )  
		cout << c;

	ifs.close();
}


void WriteFile()
{
	ofstream ofs;
	ofs.open("test.txt",ios::out);
	ofs << "hello world" << endl;
	ofs << "���ڵ�" << endl;
	ofs.close();
}

class Persion
{
public:
	char name[20];
	int age;
};

void Binary_Write()
{
	ofstream ofs;
	Persion p = {"������",18};
	

	ofs.open("persion.txt",ios::out|ios::binary);
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	ofs.write((const char*)&p,sizeof(p));
	ofs.close();
}

void Binary_Read()
{
	ifstream ifs;
	ifs.open("persion.txt",ios::in|ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Persion p;
	ifs.read((char*)&p, sizeof(p));

	cout <<"Name:"<< p.name <<"\nAge:" << p.age << endl;
	ifs.close();
}

int main()
{
	//WriteFile();
	//ReadFile();
	//Binary_Write();
	Binary_Read();
	return 0;
}

