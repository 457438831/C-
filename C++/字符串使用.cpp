#include <iostream>
#include <string>


using namespace std;

//�ַ����в����ַ���
void test01()
{
	string str;
	/*str = { "���abc123" };*/

	/*for (int i = 0; i < str.length(); i++)
	{
		cout << str[i] << endl;
	}*/
	while (1) {
		getline(cin, str, 'g');
		cout << str << endl;
		int a = 0;
		a = str.find("abc", 8);//�ӵڼ���Ԫ�ؿ�ʼ��
		if (a != str.npos)
			cout << a << endl;
		cout << a << endl;
		/*str.replace(str.find("abc"),3,"123");
		cout << str << endl;*/
	}

}

//question .дһ�����������������ַ�����������һ���ַ����ڵڶ����ַ�
//���г��ֵĴ�����
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

//question .��ʾ�û��������ַ�����ѡ��һ����Ϊ�ָ�����
void test03()
{
	string str1;
	char cut;
	int state1 = 0, state2 = 0, state3 = 0, state4 = 0, state5 = 0;
	cout << "�����룺";
	getline(cin,str1,'\n');
	cout << "��ѡ�� ";
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
	cout << " �е�һ����Ϊ�ָ�����";
	cin >> cut;
	//��ӡ�ָ����ַ�
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