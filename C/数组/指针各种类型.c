




//				各类指针使用介绍
int main()
{
	int a = 0;
	int* p = &a;//取a的地址值    一级指针
	int** pp = &p;//取指针P的指针   二级指针
	
	int* a[10];//数组指针
	int* (*p)[10] = &a;//指针数组  指针指向的是一个数组 数组里面放的指针
 
 
	int arr[] = { 0,1,2,3 };
	int* p = arr;//等同于&arr都是取数组首元素地址 但是加一会跳过数组大小的空间 
	int (*p)[4]= &arr;//等同于arr[];  指针指向一个数组  数组存放着int类型
	int (*ppp)(int, int);//取函数指针  指针指向一个函数
 
 
	int (*p) (int, int);
	int (*parr[5])(int,int);//函数指针的数组   函数指针存在parr数组中
	int (*(*pparr)[5])(int,int);//指向函数指针数组的指针
	return 0;
}