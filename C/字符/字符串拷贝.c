
#include <stdio.h>
#include <assert.h>
#include <string.h>

//				�ַ������������ź�����ƣ�
char* my_copy(char* goal,const char* move)
{
	if (strlen(goal) >= strlen(move))
	{
		char* a = goal;
		assert(goal && move);
		//�ȸ�ֵ�ټӼӣ���/0��ֵΪ0����
		while (*goal++ = *move++) {
			;
		}
		return a;
	}
	return NULL;
}

int main()
{
	char arr[] = {"######################"};
	char arr2[] = {"������ɽ�����ƺ��뺣��������ǧ��Ŀ������һ��¥"};
	if (my_copy(arr, arr2))
	{
		printf("%s", my_copy(arr, arr2));
	}
	else
	{
		printf("Ŀ������С�ڵ�ǰ����");
	}
	
	return 0;
}