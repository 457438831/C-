
#include <stdio.h>
#include <assert.h>

//strcat  字符串追加
//缺点：目标空间不够大就会崩溃，源字符串必须包含'\0',因为是指针操作所以不能自己追加自己
void my_strcat(char* arr1,const char* arr2)
{
	assert(arr1 && arr2);

	char* ret = arr1;
	//find '\0'
	while (*arr1++);//先解引用在++  即找到'\0'时指针又++了 所以需要--
	arr1--;
	//cat strings
	while (*arr1++ = *arr2++);//然后将数据拷贝到字符串后 包含'\0'

	return ret;  //返回指针起始位置
		
}

int main()
{
	char arr1[20] = "abcd";
	char arr2[] = "efgh";
	my_strcat(arr1,arr2);
	printf("%s",arr1);
	return 0;
}