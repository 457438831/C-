

#include <stdio.h>


//		��ʧ������     ʱ�临�Ӷ�O(n)  ���
// �����а���0--n��������������һ����û�� 
// 
//˼·��һ���������ͬ��֮���Ǳ��������������������Ȼ�������ȱ�ٵ�����ʣ�µľ���ԭ��������
int main()
{
	int arr[] = { 5,4,3,1,0 ,2};
	int length = sizeof(arr) / sizeof(arr[0]);
	int sum = 0;
	int i = 0;
	for (i = 0; i < length + 1; i++)
	{
		sum = sum ^ i;		//�������������
	}
	for  (int j = 0;j < length;j++)
	{
		sum = sum ^ arr[j];	//�����ʧԪ�ص�����
	}
	printf("��һ������:%d",sum);
	return 0;
}