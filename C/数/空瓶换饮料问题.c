#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>




//				��ƿ����������
int main()
{
	int jiage = 1;
	int money = 0;
	int drink = 0;
	int kongping = 0;
	scanf("%d",&money);
	drink = money / jiage;  //�ܽ����Ե��۵�ƿ�� ����ƿ��
	kongping = drink;
	while (kongping >= 2)
	{
		drink += kongping / 2;//��ƿ������2���ٴζһ�����ƿ��  +֮ǰ�ȵ�ƿ������ƿ��
		kongping = kongping / 2 + kongping % 2;//��ƿ�������ڶһ������������� + ʣ�µĿ�ƿ
	}
	printf("%d ",drink);
	return 0;
}