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
	int myAtoi(string str)
	{
		str.erase(0, str.find_first_not_of(" "));
		int i = 0;
		bool flag = true;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				flag = false;
			++i;
		}
		int res = 0;
		while (i < str.size() && str[i] >= '0'&&str[i] <= '9')
		{
			int tmp = str[i] - '0';
			if (flag)
			{
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp >= 7))
					return INT_MAX;
				res = res * 10 + tmp;
			}
			else
			{
				if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tmp >= 8))
					return INT_MIN;
				res = res * 10 - tmp;
			}
			++i;
		}
		return res;
	}
};

int main() 
{
	string s = "2147483648";
	Solution a;
	cout << a.myAtoi(s) << endl;


	


	system("pause");
	return 0;
}
