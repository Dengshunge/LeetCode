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
	string convert(string s, int numRows) {
		string res;
		if (numRows == 1)
			return s;
		//首
		for (int i = 0; i<s.size(); i = i + 2 * numRows - 2)
		{
			res += s[i];
		}
		//中
		for (int i = 1; i<numRows - 1; ++i)
		{
			int d = numRows - 1 - i;
			for (int m = i; m < s.size(); m = m + 2 * numRows - 2)
			{
				res += s[m];
				if (m + 2 * d < s.size())
				{
					res += s[m + 2 * d];
				}
			}
		}
		//尾
		for (int i = numRows - 1; i<s.size(); i = i + 2 * numRows - 2)
		{
			res += s[i];
		}
		return res;
	}

	string convert_network(string s, int numRows)
	{
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
	string s = "A";
	Solution a;
	cout << a.convert(s,1) << endl;



	


	system("pause");
	return 0;
}
