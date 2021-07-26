#include <iostream>
#include <string>


using namespace std;

//字符串中查找字符串
void test01()
{
	string str;
	/*str = { "你好abc123" };*/

	/*for (int i = 0; i < str.length(); i++)
	{
		cout << str[i] << endl;
	}*/
	while (1) {
		getline(cin, str, 'g');
		cout << str << endl;
		int a = 0;
		a = str.find("abc", 8);//从第几个元素开始找
		if (a != str.npos)
			cout << a << endl;
		cout << a << endl;
		/*str.replace(str.find("abc"),3,"123");
		cout << str << endl;*/
	}

}

//question .写一个程序，它读入两个字符串，计数第一个字符串在第二个字符
//串中出现的次数。
int test02(const string& str1,const string& str2)
{
	
	int number = 0;
	int position = 0;
	while (1)
	{
		position = str1.find(str2,position);
		if (position == str1.npos)
			break;
		++number;
		position += str2.size();
	}
	return number;
}

//question .提示用户从输入字符串中选择一个作为分隔符。
void test03()
{
	string str1;
	char cut;
	int state1 = 0, state2 = 0, state3 = 0, state4 = 0, state5 = 0;
	cout << "请输入：";
	getline(cin,str1,'\n');
	cout << "请选择 ";
	for (int i = 0; i < str1.size(); i++)
	{
		switch (str1[i])
		{
		case '.':
			if (state1 != 1)
			{
				state1 = 1;
				cout << ".|";
			}
			break;
		case ',':
			if (state2 != 1)
			{
				state2 = 1;
				cout << ",|";
			}
			break;
		case '@':
			if (state3 != 1)
			{
				state3 = 1;
				cout << "@|";
			}
			break;
		case ' ':
			if (state4 != 1)
			{
				state4 = 1;
				cout << " |";
			}
			break;
		default:
			break;
		}
		
	}
	cout << " 中的一个作为分隔符：";
	cin >> cut;
	//打印分割后的字符
	for (int i = 0; i < str1.size(); i++)
	{
		if (str1[i] == cut)
			cout<<endl;
		else
			cout << str1[i];
	}
		

}



int main()
{
	//string str1 = { "abc abc ab abt abcd abcdf" };
	//string str2 = { "ab" };
	//cout<< test02(str1, str2);
	
	test03();
	
	
	return 0;
}