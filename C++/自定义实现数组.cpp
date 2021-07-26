#include <iostream>

using namespace std;


//�Զ���ʵ������
template <class T>
class MyArr
{
public:
	MyArr(int capacity);//��ʼ��
	~MyArr();//����
	int getCapacity();
	int getSize();
	void push_back(T& value);
	void push_back(T&& value);
	T& operator[](int caption);//����[]

	MyArr<T>& operator=(MyArr<T>& date);//����=




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

//������β����������
template<class T>
void MyArr<T>::push_back(T& value)
{
	if (this->size >= this->mcapacity)
		return;
	this->p_arr[this->size] = value;
	this->size++;
}


//������β����������
template<class T>
void MyArr<T>::push_back(T&& value)
{
	if (this->size >= this->mcapacity)
		return;
	this->p_arr[this->size] = value;
	this->size++;
}

//��ȡ���ݴ�С
template<class T>
int MyArr<T>::getSize()
{
	return this->size;
}
//��ȡ�����С
template <class T>
int MyArr<T>::getCapacity()
{
	return this->mcapacity;
}

//��ʼ��
template <class T>
MyArr<T>::MyArr(int capacity)
{
	this->mcapacity = capacity;
	this->size = 0;
	this->p_arr = (T*)malloc(capacity * sizeof(T));//ע��malloc�����ֽ�Ϊ��λ
}

//����
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
	cout << "����ռ��СΪ��" << arr.getCapacity() << endl;
	cout << "����Ԫ�ش�СΪ��" << arr.getSize() << endl;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(i);
	}
	arr[0] = 5;
	//for (int i = 0; i < arr.getSize(); i++)
	//{
	//	cout << arr[i]<<" ";
	//}
	//cout << '\n' << "����ռ��СΪ��" << arr.getCapacity() << endl;
	//cout << "����Ԫ�ش�СΪ��" << arr.getSize() << endl;

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



