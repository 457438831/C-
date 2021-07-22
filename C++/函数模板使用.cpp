//函数模板   类模板
#include <iostream>


using namespace std;
//函数模板
template <class T>
T add(T a, T b)
{
	return a + b;
}

//类模板
template <class T>
class Person {
public:
	T age;
	T hegth;
	Person(T a, T b) {//重构函数
		this->age = a;
		this->hegth = b;
	}

	void Show() {
		cout << "age:" << age << ",hegth:" << hegth<<endl;
	}
};

//模板函数使用
template <class T>
void sort(T* arr,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i] < arr[j])//倒序
			{
				/*  此方法不兼容double类型数据
				arr[i] = arr[i] ^ arr[j];
				arr[j] = arr[i] ^ arr[j];
				arr[i] = arr[i] ^ arr[j];*/

				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

//打印
template <class T>
void print(T* arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	//cout << add(10, 20);

	//Person<int> ps(10,20);
	//ps.Show();
	  //整数
	/*int arr[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr) / sizeof(int);
	sort(arr,len);
	print(arr,len);*/
	  //小数
	/*double arr[] = {1.2,1.3,15,2.3,21,0.14};
	int len = sizeof(arr) / sizeof(double);
	sort(arr,len);
	print(arr,len);*/
	  //字符
	/*char arr[] = {'a','b','c','d'};
	int len = sizeof(arr) / sizeof(char);
	sort(arr,len);
	print(arr,len);*/
	  //字符串  因为有一个空格一个‘\0'所以有三个空行
	char arr[] = {"hello world"};
	int len = sizeof(arr) / sizeof(char);
	sort(arr, len);
	print(arr, len);
	  
	return 0;
}
