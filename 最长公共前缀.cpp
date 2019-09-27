#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
这题的思路是，要比较n个字符串的最长公共前缀，我先将其转化为比较两个字符串的最长公共前缀，然后用这个前缀和后面的字符串比较
例如先比较"flower","flow"，得到最长公共前缀"flow"，然后用这个"flow"与"flight"比较
*/
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		if (strs.size() == 0)
			return "";
		else if (strs.size() == 1)
			return strs[0];
		string res = findPrefix(strs[0], strs[1]);
		int i = 2;
		while (res != "" && i < strs.size())
		{
			res = findPrefix(res, strs[i++]);
		}
		return res;

	}

	string findPrefix(string &s1, string &s2)
	{
		auto s1_len = s1.size(), s2_len = s2.size();
		int i = 0, j = 0;
		for (; i < s1_len&&j < s2_len; ++i, ++j)
		{
			if (s1[i] != s2[j])
				break;
		}
		if (i == s1_len)
			return s1;
		else if (j == s2_len)
			return s2;
		else if (i == 0 || j == 0)
			return "";
		else
			return s1.substr(0, i);
	}
};

//
class Solution2 {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		int len = strs.size();
		if (len == 0)
			return "";
		if (len == 1)
			return strs[0];
		string res = findTowLongest(strs[0], strs[1]);
		for (int i = 2; i<len; ++i)
		{
			if (res == "")
				return res;
			res = findTowLongest(res, strs[i]);
		}
		return res;
	}

	string findTowLongest(string &s1, string &s2)
	{
		string res;
		for (int i = 0; i<s1.size() && i<s2.size(); ++i)
		{
			if (s1[i] == s2[i])
				res += s1[i];
			else
				break;
		}
		return res;
	}

	string longestCommonPrefix_network(vector<string>& strs) {

		string common_for = "";
		size_t common_len = 0;

		if (strs.empty())   return common_for;

		for (auto iter = strs.cbegin();iter != strs.cend();++iter)
		{
			if (iter == strs.cbegin()) {
				common_for = *iter;
				common_len = common_for.length();
				continue;
			}

			common_len = common_len < iter->length() ? common_len : iter->length();

			for (int i = 0;i < common_len;++i) 
			{
				if (common_for[i] != (*iter)[i]) 
				{
					common_len = i;
					break;
				}
			}
		}

		return common_for.erase(common_len);
	}
};

//update 2019.9.27
class Solution3 {
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		string res;
		if (strs.empty())
			return res;
		for (int i = 0; i < strs[0].size(); ++i)
		{
			char tmp = strs[0][i];
			for (int m = 1; m < strs.size(); ++m)
			{
				if (i >= strs[m].size() || strs[m][i] != tmp)
					return res;
			}
			res += tmp;
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<string> strs{ "dog","racecar","car" };
	cout << a.longestCommonPrefix(strs) << endl;


	system("pause");

}

