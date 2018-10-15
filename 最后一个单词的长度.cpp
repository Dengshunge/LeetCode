#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) 
	{
		int length = s.size();
		int i = length - 1;
		while (i >= 0 && s[i] == ' ')
			--i;
		length = i + 1;
		for (; i >= 0; --i)
		{
			if (s[i] == ' ')
				break;
		}
		return length - i - 1;
	}
};


int main()
{
	string s = "  a   ";
	Solution a;
	cout << a.lengthOfLastWord(s) << endl;


	system("pause");
}


