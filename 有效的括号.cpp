#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>

using namespace std;


class Solution {
public:
  //update 2019.10.7
	bool isValid(string s) 
	{
		vector<char> stack;
		map<char, char> left_to_right = { {'{','}'},{'[',']'},{'(',')'} };
		for (auto c : s)
		{
			if (c == '{' || c == '[' || c == '(')
				stack.push_back(c);
			else
			{
				if (stack.empty())
					return false;
				char correspond = left_to_right[stack.back()];
				if (c != correspond)
					return false;
				else
					stack.pop_back();
			}
		}
		return stack.empty();
	}
};


int main()
{
	Solution a;

	cout << boolalpha << a.isValid("]") << endl;

	system("pause");
}

