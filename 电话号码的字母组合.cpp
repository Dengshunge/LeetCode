#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> res;
		string oldstring = "";
		if (digits.empty())
			return res;
		for (auto c : NumsToString[digits[0] - '0'])
		{
			oldstring = c;
			letterCombinations_Core(digits, 1, oldstring, res);
		}
		return res;
		
	}
private:
	vector<string> NumsToString{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	void letterCombinations_Core(string digits, int index, string oldstring, vector<string> &res)
	{
		if (index == digits.size())
		{
			res.push_back(oldstring);
		}
		else
			for(auto c:NumsToString[digits[index]-'0'])
			{
				letterCombinations_Core(digits, index + 1, oldstring + c, res);
			}
	}
};

//
class Solution2 {
public:
	vector<string> letterCombinations(string digits) 
	{
		vector<string> res;
		if (digits.empty())
			return res;
		string path;
		letterCombinations(res, path, digits);
		return res;
	}

	vector<string> letterCombinations_network(string digits)
	{
		vector<string>numToString{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		if (digits.empty())
			return {};
		queue<string> re;
		re.push("");
		for (int i = 0; i < digits.size(); ++i)
		{
			int length = re.size();
			for (int j = 0; j < length; ++j)
			{
				string tmp = re.front();
				re.pop();
				for (auto c : numToString[digits[i] - '0'])
				{
					re.push(tmp + c);
				}
			}
		}
		vector<string> res;
		while (!re.empty())
		{
			res.push_back(re.front());
			re.pop();
		}
		return res;
	}

private:
	vector<string>numToString{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	void letterCombinations(vector<string> &res, string path, string digits)
	{
		if (digits.empty())
		{
			res.push_back(path);
			return;
		}
		if (digits[0] != '1')
		{
			string tmpString = numToString[digits[0] - '0'];
			for (int i = 0; i < tmpString.size(); ++i)
			{
				letterCombinations(res, path + tmpString[i], digits.substr(1));
			}
		}
		else
			letterCombinations(res, path, digits.substr(1));
	}
};

int main()
{
	Solution a;
	auto x = a.letterCombinations("23");
	for (auto c : x)
		cout << c << endl;

	system("pause");

}

