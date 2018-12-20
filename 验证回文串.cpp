#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

/*
设置两个指针进行比较即可
*/

class Solution
{
public:
	bool isPalindrome(string s)
	{
		if (s.empty())
			return true;
		auto beg = s.begin(), end = s.end() - 1;
		while (beg < end)
		{
			while (beg < end && !((*beg >= '0'&&*beg <= '9') || (tolower(*beg) >= 'a' && tolower(*beg) <= 'z')))
			{
				++beg;
			}
			while (beg < end && !((*end >= '0'&&*end <= '9') || (tolower(*end) >= 'a' && tolower(*end) <= 'z')))
			{
				--end;
			}
			if (beg <= end && tolower(*beg) == tolower(*end))
			{
				++beg;
				--end;
			}
			else
				return false;
		}
		return true;
	}
};



int main()
{
	Solution a;
	string s = "race a car";
	cout << boolalpha << a.isPalindrome(s) << endl;
	
	system("pause");
}

