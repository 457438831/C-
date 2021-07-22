#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>  //ofstream 依赖库

using namespace std;

void createFile()
{
	//创建输出文件流
	ofstream out_file;
	out_file.open("test.txt");

	//write 方法
	int a = 10000;
	char arr[] = { "白日依山尽" };
	//写出int类型
	out_file.write((char*)&a, sizeof(a));
	//写出char类型
	out_file.write(arr, sizeof(arr));
	//关闭流
	out_file.close();
}

void readFile()
{
	//创建输入流
	ifstream in_file;
	in_file.open("test.txt");
	
	int a = 0;
	char arr2[20];
	in_file.read((char*)&a,sizeof(a));
	in_file.read(arr2,11);
	cout << a << "," << arr2 << endl;
	//关闭流
	in_file.close();
}

void copyFile()
{
	char date[] = { "账号：457438831  密码：12345789" };
	ofstream write_file;
	write_file.open("date.txt");
	write_file.write(date, sizeof(date));
	write_file.close();

	//read file and copy file
	ifstream read_file;
	read_file.open("date.txt");
	char aa[100];
	read_file.seekg(0, ios::end);
	int size = read_file.tellg();
	read_file.seekg(0, ios::beg);
	read_file.read(aa, size);
	cout << aa;
	read_file.close();
	ofstream newFile;
	newFile.open("d:\\date.txt");
	newFile.write(aa, size);
	newFile.close();

}


//<<操作文件
void moveFile()
{
	ofstream file;
	file.open("test.txt");
	file << 2001 << endl;
	file << 2008 << endl;
	file.close();

	ifstream in_file;
	in_file.open("test.txt");
	int a = 0;
	int b = 0;
	in_file >> a;
	in_file >> b;
	cout << a << b;
	in_file.close();

}

//  file size
void fileSize(string str)
{
	ifstream file;
	file.open(str);
	if (!file)
		return;
	file.seekg(0, ios::end);
	cout << "file size of " << file.tellg();
}

int main()
{
	createFile();
	readFile();
	copyFile();
	moveFile();
	fileSize();
}

