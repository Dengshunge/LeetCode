#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

/*
两种方法的思路都是一样，利用对每个字符排序，构建一个map<string,vector<string>>的数据结构。
排序后，如果是字母异位词，则会相投，否则是不同的字母异位词。
然后将该字符串压入vector<string>中。

主要突破点就是如何判断是字母异位词，方法就是排序后判断。

另外，这里如果用内置的sort，时间复杂度是O(nlogn)，但由于题目规定只能是26个字符，所以可以利用空间换效率。
先构建26个位置的vector，当每读到一个字母的时候，相应位置就加一，最后组合成排序后的字符串。
时间复杂度就变成了O(n)。
https://www.cnblogs.com/jdneo/p/5291304.html

map的初始化map<string, int> a{{"a",1},{"b",1}};//这里中间是花括号，用逗号分隔

*/

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		vector<vector<string>> res;
		map<string, int> stringToInt_map;
		int index = 0;
		for (auto s1 : strs)
		{
			string s_temp = strSort(s1);
			auto iter = stringToInt_map.find(s_temp);
			if (iter == stringToInt_map.end())
			{
				stringToInt_map[s_temp] = index;
				++index;
				res.push_back({ s1 });
			}
			else
			{
				res[iter->second].push_back(s1);
			}
		}
		return res;
	}

	vector<vector<string>> groupAnagrams2(vector<string>& strs)
	{
		unordered_map<string, vector<string>> strToSet;
		for (auto s1 : strs)
		{
			string s_temp = strSort(s1);
			strToSet[s_temp].push_back(s1);
		}
		vector<vector<string>> res;
		for (auto item : strToSet)
		{
			res.push_back(item.second);
		}
		return res;
	}

	string strSort(const string s)
	{
		vector<int> count(26, 0);
		for (int i = 0; i < s.size(); ++i)
		{
			++count[s[i] - 'a'];
		}
		string res = "";
		for (int i = 0; i < 26; ++i)
		{
			while (count[i]--)
				res += ('a' + i);
		}
		return res;
	}
};



int main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat"};
	//vector<string> strs = { "","" };
	Solution a;
	auto b = a.groupAnagrams(strs);
	for (auto m : b)
	{
		for (auto n : m)
		{
			cout << n << " ";
		}
		cout << endl;
	}


	system("pause");
}

