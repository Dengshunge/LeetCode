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
	int lengthOfLongestSubstring(string s) {
		int maxLength = 0;
		int Length = 0;
		map<char, int> letter;
		for (int i = 0; i<s.size(); ++i)
		{
			auto it = letter.find(s[i]);
			if (it == letter.end())
			{
				letter[s[i]] = i;
				++Length;
			}
			else
			{
				int d = i - it->second;
				if (d>Length)
				{
					it->second = i;
					++Length;
				}
				else
				{
					it->second = i;
					Length = d;
				}
			}
			if (Length >maxLength)
				maxLength = Length;
		}
		return maxLength;
	}

	int lengthOfLongestSubstring2(string s)
	{
		int maxLength = 0, Length = 0;
		vector<int> letter(128, -1);//要128是因为ascii有128个字符，这里没说是纯字母
		for (int i = 0; i < s.size(); ++i)
		{
			int d = i - letter[s[i]];
			letter[s[i]] = i;
			Length = (d > Length) ? Length + 1 : d;
			maxLength = max(maxLength, Length);
		}
		return maxLength;
	}
	
	//update:2019.2.14
	int lengthOfLongestSubstring3(string s) 
	{
		int max = 0;
		unordered_set<char>t;
		auto p = s.begin(), q = s.begin();
		while (q != s.end())
		{
			if (t.find(*q) == t.end())
				t.insert(*q++);
			else
			{
				if (t.size()>max) max = t.size();
				while (t.find(*q) != t.end())
					t.erase(*p++);
				t.insert(*q++);
			}
		}
		if (t.size()>max) max = t.size();
		return max;
	}
	
	//update:2019.9.11
	//与2的思路一致
	int lengthOfLongestSubstring4(string s)
	{
		int maxlength = 0;
		int len = 0;
		vector<int> letter(128, -1);
		for (int i = 0; i < s.size(); ++i)
		{
			int dif = i - letter[s[i]];
			if (letter[s[i]] == -1 || dif > len)
			{
				len++;
			}
			else
			{
				len = dif;
			}
			letter[s[i]] = i;
			maxlength = max(maxlength, len);
		}
		return maxlength;
	}

};


int main() 
{
	string s = "bbbbb";
	Solution a;
	cout << a.lengthOfLongestSubstring2(s) << endl;



	


	system("pause");
	return 0;
}
