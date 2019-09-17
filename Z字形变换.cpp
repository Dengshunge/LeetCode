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
	string convert(string s, int numRows) {
		string res;
		if (numRows == 1)
			return s;
		int cycle = 2 * numRows - 2;//循环周期
		for (int i = 0; i < numRows; ++i)//用于控制Z字形中每一列
		{
			for (int j = 0; j + i < s.size(); j += cycle)//这里的j表示每个循环的开始
			{
				res += s[j + i];
				if (i != 0 && i != numRows - 1 && j + cycle - i < s.size())
					res += s[j + cycle - i];
			}
		}
		return res;
	}
};


int main()
{
	Solution a;

	string s = "LEETCODEISHIRING";
	cout << a.convert(s, 2) << endl;

	system("pause");
}

