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
	const char Roman[4][10][10] = {
		{ "","I","II" ,"III" ,"IV" ,"V" ,"VI" ,"VII" ,"VIII" ,"IX" },//1-9
		{ "","X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },//10-90
		{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },//100-900
		{ "", "M", "MM", "MMM" }//1000-3000
	};
};

// 这道题类似于上一道题的逆转思维，首先读取每一位，然后有些位需要判断后面一位是否高于自己，而有些位置不需要
// 这个需要举例子来抽象出来找规律。
// 我一开始的想法是还需要找多少个相同的连续字母，其实这不需要考虑，我想太多了。
// 注意一点是，999的罗马数字是CMXCIX，而不是IM
class Solution2 {
public:
	int romanToInt(string s) 
	{
		int res = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			switch (s[i])
			{
			case 'M':
				res += 1000;
				break;
			case 'D':
				res += 500;
				break;
			case 'C':
				if (i < s.size() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
					res -= 100;
				else
					res += 100;
				break;
			case 'L':
				res += 50;
				break;
			case 'X':
				if (i < s.size() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
					res -= 10;
				else
					res += 10;
				break;
			case 'V':
				res += 5;
				break;
			case 'I':
				if (i < s.size() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
					res -= 1;
				else
					res += 1;
				break;
			default:
				break;
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	Solution2 b;
	int num = 999;
	string s = a.intToRoman(num);
	cout << a.intToRoman(num) << endl;
	cout << b.romanToInt(s) << endl;


	system("pause");

}

