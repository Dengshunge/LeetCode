#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		// 去除前面的空格
		str.erase(0, str.find_first_not_of(" "));
		if (str.empty())
			return 0;
		int i = 0;
		bool Flag = true;
		// 注意，这里比较不能用双引号的，因为双引号是字符串，不能直接比较
		if (str[0]=='-' || str[0]=='+')
		{
			if (str[0] == '-')
			{
				Flag = false;
			}
			++i;
		}
		//处理和面的数字
		int res = 0;
		for (; i < str.length(); ++i)
		{
			if (str[i]<'0' || str[i]>'9')
				break;
			int digit = str[i] - '0';
			if (Flag)
			{
				if (res < INT_MAX / 10 || (res == INT_MAX / 10 && digit <= 7))
					res = res * 10 + digit;
				else
					return INT_MAX;
			}
			else
			{
				if (res > INT_MIN / 10 || (res == INT_MIN / 10 && digit <= 8))
					res = res * 10 - digit;
				else 
					return INT_MIN;
			}
		}
		return res;
	}

	// 去除首尾的空格
	void trim(string &s)
	{
		if (!s.empty())
		{
			s.erase(0, s.find_first_not_of(" "));//去除前面的空格
			s.erase(s.find_last_not_of(" ") + 1);//去除尾部的空格
		}
	}
};


int main()
{
	string s = "2147483646";
	Solution a;
	cout << a.myAtoi(s) << endl;





	system("pause");

}

