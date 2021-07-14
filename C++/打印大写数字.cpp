#include <iostream>
#include <string>

using namespace std;
//将数字转为大写
string toA(int num)
{
	switch (num)
	{
	case 1:
		return "壹";
		break;
	case 2:
		return "贰";
		break;
	case 3:
		return "叁";
		break;
	case 4:
		return "肆";
		break;
	case 5:
		return "伍";
		break;
	case 6:
		return "陆";
		break;
	case 7:
		return "柒";
		break;
	case 8:
		return "捌";
		break;
	case 9:
		return "玖";
		break;
	default:
		return "error";
		break;
	}
}
//转化为大写数字
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
		case 0://个
			bag = add + bag;
			break;
		case 1://十
			bag = add+"拾" + bag;
			break;
		case 2://百
			bag = add+"百" + bag;
			break;
		case 3://千
			bag = add +"千" + bag;
			break;
		case 4://万
			bag = add+"万" + bag;
			break;
		case 5://十万
			bag = add + "拾" + bag;
			break;
		case 6://百万
			bag = add + "百" + bag;
			break;
		case 7://千万
			bag = add + "千" + bag;
			break;
		case 8://亿
			bag = add + "亿" + bag;
			break;
		case 9://十亿
			bag = add + "拾" + bag;
			break;
		case 10://百亿
			bag = add + "百" + bag;
			break;
		case 11://千亿
			bag = add + "千" + bag;
			break;
		case 12://万亿
			bag = add + "万" + bag;
			break;
		default:
			bag = "数据过大";
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