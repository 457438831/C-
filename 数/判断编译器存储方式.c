
#include <stdio.h>

//			�жϱ������Ǵ�˻���С�˴洢
//��˼� 00 00 00 01 С�˼� 01 00 00 00 
int check_sys() 
{
	int i = 1;
	return *(char*)&i;
}

int main()
{
	int i = 0;
	i = check_sys();
	if (i == 0)
	{
		printf("�ñ������Ǵ�˴洢��");
	}
	else if (i == 1) 
	{
		printf("�ñ�������С�˴洢");
	}
	return 0;
}
