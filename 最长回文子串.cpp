#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s)
	{
		strLen = s.size();
		int start = 0, end = 0;
		for (int i = 0; i<strLen; ++i)
		{
			int len1 = findlongestPalindrome(s, i, i);
			int len2 = findlongestPalindrome(s, i, i + 1);
			int len = max(len1, len2);
			if (len>(end - start + 1))
			{
				end = i + len / 2;
				start = end - len + 1;
			}
		}
		return s.substr(start, end - start + 1);

	}

private:
	int strLen = 0;
	int findlongestPalindrome(const string &s, int left, int right)
	{
		while (left >= 0 && right<strLen&&s[left] == s[right])
		{
			--left;
			++right;
		}
		return right - left - 1;
	}
};

//2019.9.16
//和上述方法一样，使用了中心扩增的方法
//面对对称的问题，可以使用中心扩展的方法，即从中间向两边进行考虑
class Solution2 {
public:
	string longestPalindrome(string s)
	{
		if (s.empty())
			return s;
		int length = s.size();
		int maxlen = 1;
		string maxstr = "";
		for (int i = 0; i < length; ++i)
		{
			//回文为奇数
			int odd = judge(s, i, i);
			//回文为偶数
			int even = judge(s, i, i + 1);
			string tmp = (odd > even) ? s.substr(i - int(odd / 2), odd) : s.substr(i - int(even / 2) + 1, even);
			if (tmp.size() >= maxlen)
			{
				maxlen = tmp.size();
				maxstr = tmp;
			}
		}
		return maxstr;
	}
private:
	int judge(string s, int left, int right)
	{
		for (; left >= 0 && right < s.size(); left--, right++)
		{
			if (s[left] != s[right])
			{
				break;
			}
		}
		return right - left - 1;
	}
};

int main() 
{
	string s = "cbbd";
	Solution a;
	cout << a.longestPalindrome(s) << endl;



	


	system("pause");
	return 0;
}
