#include <iostream>
#include <string>

using namespace std;
//������תΪ��д
string toA(int num)
{
	switch (num)
	{
	case 1:
		return "Ҽ";
		break;
	case 2:
		return "��";
		break;
	case 3:
		return "��";
		break;
	case 4:
		return "��";
		break;
	case 5:
		return "��";
		break;
	case 6:
		return "½";
		break;
	case 7:
		return "��";
		break;
	case 8:
		return "��";
		break;
	case 9:
		return "��";
		break;
	default:
		return "error";
		break;
	}
}
//ת��Ϊ��д����
string toChinese(long long num)
{
	string bag = " ";
	string add = " ";
	int bit = 0;
	int remainder = 0;
	while (num)
	{
		remainder = num % 10;
		num = num / 10;
		add = toA(remainder);
		switch (bit)
		{
		case 0://��
			bag = add + bag;
			break;
		case 1://ʮ
			bag = add+"ʰ" + bag;
			break;
		case 2://��
			bag = add+"��" + bag;
			break;
		case 3://ǧ
			bag = add +"ǧ" + bag;
			break;
		case 4://��
			bag = add+"��" + bag;
			break;
		case 5://ʮ��
			bag = add + "ʰ" + bag;
			break;
		case 6://����
			bag = add + "��" + bag;
			break;
		case 7://ǧ��
			bag = add + "ǧ" + bag;
			break;
		case 8://��
			bag = add + "��" + bag;
			break;
		case 9://ʮ��
			bag = add + "ʰ" + bag;
			break;
		case 10://����
			bag = add + "��" + bag;
			break;
		case 11://ǧ��
			bag = add + "ǧ" + bag;
			break;
		case 12://����
			bag = add + "��" + bag;
			break;
		default:
			bag = "���ݹ���";
			break;
		}
		bit++;
	}
	return bag;
}

int main()
{
	long long num = 1;
	while (num > 0)
	{
		cin >> num;
		string str = toChinese(num);
		cout << str<<endl;
	}
	return 0;
}