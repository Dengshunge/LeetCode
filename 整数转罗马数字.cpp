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
	
	//2019.3.1
	string intToRoman(int num) {
		string roman;
		while (num) {
			if (num >= 1000) 
			{ num -= 1000; roman += 'M'; }
			else 
			{
				if (num >= 900) 
				{ num -= 900; roman += 'C'; roman += 'M'; }
				else 
				{
					if (num >= 500) 
					{ num -= 500; roman += 'D'; }
					else 
					{
						if (num >= 400) 
						{ num -= 400; roman += 'C'; roman += 'D'; }
						else 
						{
							if (num >= 100) 
							{ num -= 100; roman += 'C'; }
							else 
							{
								if (num >= 90) 
								{ num -= 90; roman += 'X'; roman += 'C'; }
								else 
								{
									if (num >= 50) 
									{ num -= 50; roman += 'L'; }
									else 
									{
										if (num >= 40) 
										{ num -= 40; roman += 'X'; roman += 'L'; }
										else 
										{
											if (num >= 10) 
											{ num -= 10; roman += 'X'; }
											else 
											{
												if (num >= 9) 
												{ num -= 9; roman += 'I'; roman += 'X'; }
												else 
												{
													if (num >= 5) 
													{ num -= 5; roman += 'V'; }
													else 
													{
														if (num >= 4) 
														{ num -= 4; roman += 'I'; roman += 'V'; }
														else 
														{ num -= 1; roman += 'I'; }
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return roman;
	}
	
	//update 2019.9.25
	string intToRoman(int num) {
		map<int, string> mapRom = { { 1,"I" },{ 4,"IV" },{ 5,"V" },{ 9,"IX" },{ 10,"X" },{ 40,"XL" },{ 50,"L" },{ 90,"XC" },{ 100,"C" },{ 400,"CD" },{ 500,"D" },{ 900,"CM" },{ 1000,"M" } };
		map<int, string>::reverse_iterator  r_iter;

		string ret;

		r_iter = mapRom.rbegin();
		while (r_iter != mapRom.rend())
		{
			if (num >= r_iter->first)
			{
				ret += r_iter->second;
				num -= r_iter->first;
			}
			else
				r_iter++;
		}
		return ret;
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

