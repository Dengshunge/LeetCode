#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
一开始想到的是递归的方法，结果超时了。
到最后也没想出好方法，网上说使用动态规划。

result[i]表示能否在i位置进行切分。
想要知道在i位置能否切分，则需要判断j位置能否切分(0<=j<=i)
当j==i时，判断字符从0到i能否切分。
当j<i时，若result[j]==true，说明已经能在j位置进行切分，然后判断j+1到i位置能否切分，如果能，使result[i]=true

https://blog.csdn.net/u012501459/article/details/46717915
https://blog.csdn.net/feliciafay/article/details/18999903
*/

class Solution 
{
public:
	//方法一，递归
	bool wordBreak(string s, vector<string>& wordDict) 
	{
		if (s.empty())
			return true;
		for (int i = 1; i <= s.size(); ++i)
		{
			string s1 = s.substr(0, i);
			if (find(wordDict.begin(), wordDict.end(), s1) != wordDict.end())
			{
				if (wordBreak(s.substr(i), wordDict))
					return true;
			}
		}
		return false;
	}

	//方法二，动态规划
	bool wordBreak_network(string s, vector<string>& wordDict)
	{
		vector<bool> result(s.size(), false);
		for (int i = 0; i < s.size(); ++i)
		{
			for (int j = i; j >= 0; --j)
			{
				if (j == i)
					result[i] = isCheck(s.substr(0, i + 1), wordDict);
				else if (result[j])
					result[i] = isCheck(s.substr(j + 1, i - j), wordDict);
				if (result[i])
					break;
			}
		}
		return result.back();
	}

	bool isCheck(const string &s, vector<string>& wordDict)
	{
		return (find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) ? true : false;
	}
};


int main() 
{
	string s = "catsandog";
	vector<string> wordDict{ "cats", "dog", "sand", "and", "cat" };
	Solution a;
	cout << boolalpha << a.wordBreak(s, wordDict) << endl;

	system("pause");
	return 0;
}
