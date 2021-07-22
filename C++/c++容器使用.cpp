/*********************************************
* 标题：			MFC  windows 接口调用
*********************************************/
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using namespace std;

//vector 使用 动态数组形式存储
void vct()
{
	vector<int> arr;
	arr.insert(arr.begin(),1);
	arr.push_back(4);
	arr.insert(arr.end(), { 3,7,9,3,6,8,3,5,2,3,7 });
	for (int i = 0; i < arr.size(); i++)
	{
		if (3 == arr[i])
			arr.erase(arr.begin()+i);
		cout << arr[i] << ",";
	}
	cout << endl;
}

void vect()
{
	vector<int> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.insert(arr.begin(),1);
		cout << arr.data()<<endl;
		arr.push_back(5);
		cout << arr.data()<<endl;
	}
}

//list 使用    链表形式
void lt()
{
	list<int> arr;
	arr.push_front(1);
	arr.insert(arr.end(),4);
	arr.insert(arr.end(),{3,7,9,3,6,8,3,5,2,3,7,3});
	list<int>::iterator ite,remenber;
	remenber = ite = arr.begin();

	//delete 3
	int size = arr.size();
	for(int i = 0;i < size;i++)
	{
		if (3 != *ite)
			cout << *ite << endl;
		remenber++;
		if (3 == *ite)
		{
			arr.erase(ite);
			ite = remenber;
		}
		else
		{
			ite++;
		}
	}
}

//map 使用
void mp()
{
	map<int, char> stu;
	stu[10010] = 'm';
	stu[10011] = 'f';
	stu[10012] = 'f';
	stu[10013] = 'm';
	stu[10014] = 'f';
	stu[10015] = 'm';
	map<int, char>::iterator ite,remenber;
	remenber = stu.begin();
	for (ite = stu.begin(); ite != stu.end();)
	{
		remenber++;
		if (ite->second == 'm')
		{
			stu.erase(ite);
			ite = remenber;
		}else
		{
			cout << "num:" << ite->first << "value:" << ite->second << endl;
			ite++;
		}
	}
}
int main()
{
	
	//moveFile();
	//fileSize("test.txt");
	//vct();
	//vect();
	//lt();
	mp();

	return 0;
}


