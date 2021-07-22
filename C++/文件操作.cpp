#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>  //ofstream ������

using namespace std;

void createFile()
{
	//��������ļ���
	ofstream out_file;
	out_file.open("test.txt");

	//write ����
	int a = 10000;
	char arr[] = { "������ɽ��" };
	//д��int����
	out_file.write((char*)&a, sizeof(a));
	//д��char����
	out_file.write(arr, sizeof(arr));
	//�ر���
	out_file.close();
}

void readFile()
{
	//����������
	ifstream in_file;
	in_file.open("test.txt");
	
	int a = 0;
	char arr2[20];
	in_file.read((char*)&a,sizeof(a));
	in_file.read(arr2,11);
	cout << a << "," << arr2 << endl;
	//�ر���
	in_file.close();
}

void copyFile()
{
	char date[] = { "�˺ţ�457438831  ���룺12345789" };
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


//<<�����ļ�
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

