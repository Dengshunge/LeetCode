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
};


int main() 
{
	string s = "bbbbb";
	Solution a;
	cout << a.lengthOfLongestSubstring2(s) << endl;



	


	system("pause");
	return 0;
}
