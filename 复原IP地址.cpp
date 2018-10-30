#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

/*
思路很明显，就是递归
但这题难的地方是递归的条件有2个，分别是是否分成了4段和是否用完全部字符。

https://www.cnblogs.com/ariel-dreamland/p/9159611.html
*/

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> res;
		if (s.size() >= 4 && s.size() <= 12)
			restoreIpAddresses(s, res, "", 4);
		return res;
	}

	//k代表还需要分成k段
	void restoreIpAddresses(string s, vector<string> &res, string path, int k)
	{
		if (k == 0)
		{
			//当用完全部字符，才插入结果中
			if (s.empty())
				res.push_back(path);
			return;
		}
		//这里i表示每段数字的位数
		for (int i = 1; i <= 3; ++i)
		{
			if (s.size() >= i && isValid(s.substr(0, i)))
			{
				if (k == 1)
					restoreIpAddresses(s.substr(i), res, path + s.substr(0, i), k - 1);
				else
					restoreIpAddresses(s.substr(i), res, path + s.substr(0, i) + ".", k - 1);
			}
		}
	}

	bool isValid(string s)
	{
		if (s.size() > 1 && s[0] == '0')
			return false;
		int temp = atoi(s.data());
		return temp <= 255 && temp >= 0;
	}
};



int main() 
{
	string s1 = "10000";
	Solution a;
	auto b = a.restoreIpAddresses(s1);
	for (auto m : b)
		cout << m << endl;




	system("pause");
	return 0;
}



