#include <iostream>
#include <string>
using namespace std;

// 此题的关键是建议一个查询表！！
// 用一定空间来换取效率
class Solution {
public:
	string intToRoman(int num) 
	{
		string res = "";
		if (num >= 1 && num <= 3999)
		{
			int i = 0;
			while (num != 0)
			{
				int temp = num % 10;
				num /= 10;
				res = string(Roman[i][temp]) + res;
				++i;
			}
		}
		return res;
	}
private:
	//4是说明有4个，第一个10说明每个里面有10个字符串，第二个10说明每个字符串有10个字符
	const char Roman[4][10][10]={
		{"","I","II" ,"III" ,"IV" ,"V" ,"VI" ,"VII" ,"VIII" ,"IX" },//1-9
	{"","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },//10-90
	{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },//100-900
	{ "", "M", "MM", "MMM" }//1000-3000
	};
};

int main()
{
	Solution a;
	cout << a.intToRoman(3999) << endl;

	system("pause");

}

