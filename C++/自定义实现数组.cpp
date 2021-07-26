#include <iostream>

using namespace std;


//自定义实现数组
template <class T>
class MyArr
{
public:
	MyArr(int capacity);//初始化
	~MyArr();//析构
	int getCapacity();
	int getSize();
	void push_back(T& value);
	void push_back(T&& value);
	T& operator[](int caption);//重载[]

	MyArr<T>& operator=(MyArr<T>& date);//重载=




private:
	int mcapacity;
	int size;
	T* p_arr;
};



template<class T>
MyArr<T>& MyArr<T>::operator=(MyArr<T>& date)
{
	if (this->p_arr != NULL)
	{
		free(this->p_arr);
		this->p_arr = NULL;
	}
	this->mcapacity = date.mcapacity;
	this->size = date.size;
	this->p_arr = date.p_arr;

	return *this;
}

template<class T>
T& MyArr<T>::operator[](int caption)
{
	return this->p_arr[caption];
}

//往数组尾部插入数据
template<class T>
void MyArr<T>::push_back(T& value)
{
	if (this->size >= this->mcapacity)
		return;
	this->p_arr[this->size] = value;
	this->size++;
}


//往数组尾部插入数据
template<class T>
void MyArr<T>::push_back(T&& value)
{
	if (this->size >= this->mcapacity)
		return;
	this->p_arr[this->size] = value;
	this->size++;
}

//获取数据大小
template<class T>
int MyArr<T>::getSize()
{
	return this->size;
}
//获取数组大小
template <class T>
int MyArr<T>::getCapacity()
{
	return this->mcapacity;
}

//初始化
template <class T>
MyArr<T>::MyArr(int capacity)
{
	this->mcapacity = capacity;
	this->size = 0;
	this->p_arr = (T*)malloc(capacity * sizeof(T));//注：malloc是以字节为单位
}

//析构
template <class T>
MyArr<T>::~MyArr()
{
	if (this->p_arr != NULL)
	{
		free(this->p_arr);
		p_arr = NULL;
	}
}

void test04()
{
	MyArr<int> arr(10), arr2(2);
	cout << "数组空间大小为：" << arr.getCapacity() << endl;
	cout << "数组元素大小为：" << arr.getSize() << endl;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(i);
	}
	arr[0] = 5;
	//for (int i = 0; i < arr.getSize(); i++)
	//{
	//	cout << arr[i]<<" ";
	//}
	//cout << '\n' << "数组空间大小为：" << arr.getCapacity() << endl;
	//cout << "数组元素大小为：" << arr.getSize() << endl;

	//arr2.push_back(100);
	//arr2.push_back(200);
	//cout << arr2.getCapacity()<<endl;
	//cout << arr2.getSize()<<endl;
	//cout << arr2[0]<<endl;
	//cout << arr2[1] << endl;
	//arr = arr2;

}

int main()
{

	test04();

	return 0;
}



