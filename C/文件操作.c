#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct student
{
	char* name;//char arr[20]   c++不支持直接赋值 初始化时可以赋值
	int age;
	int height;
};

void write_file()
{
	struct student stu;
	stu.name = "张三";
	stu.age = 25;
	stu.height = 170;

	FILE* file = fopen("test.txt","wb");
	if (!file)
		return;
	fwrite(stu.name,1,5,file);
	fwrite(&stu.age,4,1,file);
	fwrite(&stu.height,4,1,file);
	fclose(file);
}

void read_file()
{
	struct student stu;
	FILE* file = fopen("test.txt","rb");
	if (!file)
		return;
	char name[20];
	fread(name,1,5,file);
	fread(&stu.age,4,1,file);
	fread(&stu.height,4,1,file);
	fclose(file);
	stu.name = name;

	printf("name:%s\n",stu.name);
	printf("age:%d\n",stu.age);
	printf("height:%d\n",stu.height);
	
}

int main()
{
	write_file();
	read_file();


	return 0;
}