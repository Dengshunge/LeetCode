#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
这题就是统计几个数字相同
但练习了几个不常用的用法:
1.利用to_string(int)  -> 就是将int转换为string。如果Int<10的话，还可以通过int + '0' 来转换成string。
2.string是一种容器，其是由char组成。可以对string使用=，也可以对char使用=。
3.利用typeid(xx).name()来查查xx的类型。
*/

class Solution
{
public:
	string countAndSay(int n) 
	{
		vector<string> res{ "1" };
		for (int i = 1; i < n ; ++i)
		{
			string lastStr = res.back();
			string newStr;
			int j = 0, sameNum = 1;
			while (j < lastStr.size())
			{
				if (lastStr[j + 1] == lastStr[j])
				{
					++sameNum;
				}
				else
				{
					newStr = newStr + to_string(sameNum) + lastStr[j];
					sameNum = 1;
				}
				++j;
			}
			res.push_back(newStr);
		}
		return res.back();
	}
	
	//
	string countAndSay(int n) 
	{
		string s = "1";
		for (int i = 2; i <= n; ++i)
		{
			int j = 0;
			string tmp = "";
			while (j < s.size())
			{
				int num = 0;
				char each_char = s[j];
				while (each_char == s[j])
				{
					num++;
					j++;
				}
				tmp += to_string(num) + each_char;
			}
			s = tmp;
		}
		return s;
	}
};



int main()
{
	Solution a;
	cout << a.countAndSay(20) << endl;


	system("pause");

}

