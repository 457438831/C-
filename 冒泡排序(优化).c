#include <stdio.h>



//				ð������(Ч���Ż�)
void maopao(int arr[], int length) {//���鴫�ݲ��� ֻ���ݵ�һ��ֵ�ĵ�ֵַ
	int i = 0;
	for (i = 0; i < length; i++)
	{
		int flag = 1;// �����ж��Ƿ��Ѿ�����
		int b = 0;
		for (b = 0; b < length-1-i; b++)//���lengthֻ��һ���ж�����㣬��������
		{
			if (arr[b] > arr[b + 1]) {
				int tmp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}

int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,0};
	int i = 0;
	int length = sizeof(arr) / sizeof(arr[0]);
	maopao(arr,length);
	for (i = 0; i < length; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}