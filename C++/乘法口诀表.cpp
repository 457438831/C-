#include <iostream>//包含IO文件

using namespace std;  //使用命名管道

void table()//如果函数放到main函数之下 就需要声明   因为系统读文件是从上往下
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
	table();//打印乘法口诀表
}

