#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct persion
{
	string name;
	int age;
	int height;
};

void write_file()
{
	persion zhangsan;
	zhangsan.name = "уехЩ";
	zhangsan.age = 25;
	zhangsan.height = 170;
	ofstream file;
	file.open("test.txt");
	if (!file)
		return;
	//name
	file.write((char*)&zhangsan.name,sizeof(string));
	//age 
	file.write((char*)&zhangsan.age, sizeof(int));
	//height
	file.write((char*)&zhangsan.height,sizeof(int));
	cout << "write ok"<<endl;
	file.close();
}

void read_file()
{
	persion stu;
	ifstream file;
	file.open("test.txt");
	if (!file)
		return;
	
	file.read((char*)&stu.name,sizeof(string));
	file.read((char*)&stu.age,sizeof(int));
	file.read((char*)&stu.height,sizeof(int));
	
	cout << "name:" << stu.name << endl;
	cout << "age:" << stu.age << endl;
	cout << "height:" << stu.height << endl;
	
	file.close();
}

int main()
{
	write_file();
	read_file();
	
	return 0;
}

