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

int main()
{
	Solution a;
	auto x = a.letterCombinations("23");
	for (auto c : x)
		cout << c << endl;

	system("pause");

}

