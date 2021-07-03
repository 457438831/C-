
#include <stdio.h>
#include <assert.h>


// strstr 查找字符串是否存在   (自定义) 并返回下标
int my_strstr(const char* arr1,const char* arr2)
{
	assert(arr1 && arr2);
	const char* string = arr1;
	const char* find = arr2;
	const char* log = arr1;
	//recording count  记录下标
	int count = 0;						//用于记录Log指针移动的次数，即下标
	if (0 == *find)					    //如果arr2为'\0'即0则无需查找
		return -1;
	while (*string)						//被查找的字符串不能为空即'\0'
	{
		string = log;					//log用于记录查找的位置
		find = arr2;					//每次比较重置find指针位置至起始位置
		while (*string == *find)
		{
			if (*string == '\0')
			{//	末尾相等
				return count;
			}
			string++;
			find++;
		}
		//    中间相等
		if (*find == '\0')
			return count;
		count++;
		log++;
	}
	//  不相等
	return -1;
}

int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcd";
	int find = my_strstr(arr1,arr2);
	if (find != -1)
	{
		printf("find，下标是:%d",find);
	}
	else {
		printf("not find");
	}
	return 0;
}