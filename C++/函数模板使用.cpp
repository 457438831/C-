//����ģ��   ��ģ��
#include <iostream>


using namespace std;
//����ģ��
template <class T>
T add(T a, T b)
{
	return a + b;
}

//��ģ��
template <class T>
class Person {
public:
	T age;
	T hegth;
	Person(T a, T b) {//�ع�����
		this->age = a;
		this->hegth = b;
	}

	void Show() {
		cout << "age:" << age << ",hegth:" << hegth<<endl;
	}
};

//ģ�庯��ʹ��
template <class T>
void sort(T* arr,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i] < arr[j])//����
			{
				/*  �˷���������double��������
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

//��ӡ
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
	  //����
	/*int arr[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr) / sizeof(int);
	sort(arr,len);
	print(arr,len);*/
	  //С��
	/*double arr[] = {1.2,1.3,15,2.3,21,0.14};
	int len = sizeof(arr) / sizeof(double);
	sort(arr,len);
	print(arr,len);*/
	  //�ַ�
	/*char arr[] = {'a','b','c','d'};
	int len = sizeof(arr) / sizeof(char);
	sort(arr,len);
	print(arr,len);*/
	  //�ַ���  ��Ϊ��һ���ո�һ����\0'��������������
	char arr[] = {"hello world"};
	int len = sizeof(arr) / sizeof(char);
	sort(arr, len);
	print(arr, len);
	  
	return 0;
}
