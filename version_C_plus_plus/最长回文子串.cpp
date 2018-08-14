#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s)
	{
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = len1 > len2 ? len1 : len2;
			if (len > (end - start + 1))
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		while ((left >= 0) && (right < s.size()) && (s[left] == s[right]))
		{
			--left;
			++right;
		}
		return right - left - 1;
	}
};

int main()
{
	string s = "ababd";
	Solution a;
	auto b = a.longestPalindrome(s);
	cout << b << endl;
	system("pause");
	return 0;
}
