/*=============================================================
	文件名称:文件操作
	作    者:小花儿
	编写时间:2021.10.27 13:56
	修改时间:
	内容简介:
	 利用多态 模拟计算机组装
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
		cout << "文件打开失败" << endl;
		return;
	}
	char buff[1024] = { 0 };
	//第一种 
	/*
	while (ifs.getline(buff, sizeof(buff)))
		cout << buff << endl;;*/

	//第二种
	/*while (ifs >> buff)     重载运算符是按空格切分字符
		cout << buff << endl;*/
	//第三种
	/*string str;
	while (getline(ifs, str))
		cout << str << endl;*/
	//第四种
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
	ofs << "三口到" << endl;
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
	Persion p = {"张三丰",18};
	

	ofs.open("persion.txt",ios::out|ios::binary);
	if (!ofs.is_open())
	{
		cout << "文件打开失败" << endl;
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
		cout << "文件打开失败" << endl;
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

