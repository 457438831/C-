


//            ��ʶC����
//	��ͷ�ļ� <name.h>���ÿ⺯��    "name.h"�����Զ��庯����
#include <stdio.h>
#include <string.h>

//	�ṹ�崴��
struct game {

	char name[20];
	short xue;
	short lan;
	int gongji;
};


int main() {

	// �ṹ�崴������ʼ��
	struct game xixi = {"123456",200,100,50};

	//�ṹ������޸�
	strcpy(xixi.name,"C����"); //�ַ��޸Ĳ���ֱ�Ӹ�ֵ
	xixi.xue = 200;
	xixi.lan = 100;
	xixi.gongji = 50;

	printf("���ƣ�%s\n",xixi.name);
	printf("HP:%d\n",xixi.xue);
	printf("MP:%d\n",xixi.lan);
	printf("GJ:%d\n",xixi.gongji);

	// �ṹ���������ʹ�ã�ָ��ʵ�֣�
	struct game* pd = &xixi;
	printf("���ƣ�%s\n",pd->name);
	printf("HP:%d\n",pd->xue);
	printf("MP:%d\n",pd->lan);
	printf("GJ:%d\n",pd->gongji);
	return 0;
}

