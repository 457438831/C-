
#include <stdio.h>
#include <math.h>


//		��0--10W֮�ڵ�ˮ�ɻ���     ˮ�ɻ���=ÿλ����λ���η��ĺͣ�����������
int main()
{
	int i = 0;
	for (i = 0; i < 100000; i++)
	{
		//  ��������Ǽ�λ��    
		int num = 1;
		int tmp = i;
		while (tmp/=10)//������Ϊ��  ��nΪλ��
		{
			num++;
		}
		//		��ÿλ����ƽ��֮��
		int a = i;
		int sum = 0;
		int j = 0;
		for ( j = 0; j < num; j++)
		{
			sum += pow(a % 10, num);//pow��һ�����Ĵη�
			a = a / 10;
		}
		//			�жϺ��Ƿ��뱾�����
		if (sum == i)
		{
			printf("%d \n",i);
		}
	}
	return 0;
}
