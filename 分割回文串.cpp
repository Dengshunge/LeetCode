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
一开始没什么思路，参考了https://blog.csdn.net/u012501459/article/details/46792453

例如分割字符串"abcbad"。
1.分成"a"和"bcbad"，判断"a"是否回文
2.将"bcbad"分成"b"和"cbad"，判断"b"是否回文3
重复，将原字符串切割成一个一个字母，如a/b/c/b/a/d/。当切割到最后，压入result中
然后回溯a/b/c/b/ad，判断"ad"是否是回文，再回溯成a/b/c/bad，判断"bad"是否是回文。
其中在判断"bad"是否是回文，会切割成ba/d来进行再次判断。

其中，这里需要引入一个pos来判断是否切割到最后，而不是根据path.size()来判断

*/


class Solution 
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		vector<string> path;
		partition(s, 0, result, path);
		return result;
	}

private:
	void partition(string s, int pos, vector<vector<string>> &result, vector<string> &path)
	{
		if (pos == s.size())
		{
			result.push_back(path);
			return;
		}
		for (int i = pos; i < s.size(); ++i)
		{
			string tmp = s.substr(pos, i - pos + 1);
			if (check(tmp))
			{
				path.push_back(tmp);
				partition(s, i + 1, result, path);
				path.pop_back();
			}
		}
	}

	bool check(string s)
	{
		int beg = 0, end = s.size() - 1;
		while (beg < end)
		{
			if (s[beg++] != s[end--])
				return false;
		}
		return true;
	}
};


int main() 
{
	string s = "abcbcad";
	Solution a;
	auto b = a.partition(s);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
