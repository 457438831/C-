#include <stdio.h>


//���ֲ��ҷ�
int main() {
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int want = 10;
	int left = 0;//���±�
	int rigth = sizeof(arr) / sizeof(arr[0])-1;//���±�
	while (left<=rigth) {
		int mid = (left + rigth) / 2;  //ȡ�м�ֵ
		if (arr[mid] > want) 
		{
			rigth = mid -1;
		}
		else if (arr[mid] < want) 
		{
			left = mid +1;
		}
		else if(arr[mid] == want)
		{
			printf("�±��ǣ�%d\n", mid);
			break;
		}
	}
	if (left>rigth)
	{
		printf("δ�ҵ���");
	}
	return 0;
}