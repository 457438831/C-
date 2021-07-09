
#include <stdio.h>


//    一个数组中有两个数只出现了一次
//   思路：将数组中所有元素异或 得到两个不一样的数异或  因（异或：相同为零不同为一）即找出结果中第一个不同的bit位  再将
//   整个数组中此位不同的元素分成两组 分别进行异或结果得到两个只出现一次的数
int main()
{
	int arr1[] = {2,6,6,2,55,101};
	int length = sizeof(arr1) / sizeof(arr1[0]);
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum = sum ^ arr1[i]; //将所有元素进行异或   得到两个单一数的异或
	}

	for (int i = 0; i < 32; i++)
	{
		
		if ((sum >> i)& 1)  //判断异或后的值  查找第几位是1  因为异或后的值为1即表明两个数此位上的值不同
		{
			int a = 0;
			int b = 0;
			for (int j = 0; j < length;j++)
			{
				if ((arr1[j] >> i )& 1)//将不同位为一的元素进行异或
				{
					a = a ^ arr1[j];   //将第N位不同的数分开进行异或  则分别得到两个只出现一次的数
				}else				   //将不同为为0的元素进行异或
				{
					b = b ^ arr1[j];
				}
			}
			if(a < b) //进行判断排序   大到小排列
			{ 
				a = a ^ b;
				b = a ^ b;
				a = a ^ b;
			}
			printf("%d %d", a, b);
			break;
		}
	}
	return 0;
}