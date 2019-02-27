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

int main() 
{
	string s = "cbbd";
	Solution a;
	cout << a.longestPalindrome(s) << endl;



	


	system("pause");
	return 0;
}
