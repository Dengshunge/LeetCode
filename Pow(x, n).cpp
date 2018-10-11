#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;


/*
思路不难，x^n=(x^(n/2))^2，如果n是奇数，还需要再乘以x。
就是迭代法。
但有些细节需要注意：
负数的最小值的绝对值仍然是负数，因为int的范围是(-2^31,2^31-1)。所以我的做法是先让其编程INT_MIX，最后再乘上x
*/
class Solution
{
public:
	double myPow(double x, int n)
	{
		if (x == 1)
			return 1;
		double res;
		if (n == INT_MIN)
		{
			res = myPow_Core(x, abs(n + 1));
			res *= x;
		}
		else
			res = myPow_Core(x, abs(n));
		if (n < 0)
			return 1 / res;
		else
			return res;
	}

	double myPow_Core(double x, int n)
	{
		if (n == 0)
			return 1;
		else if (n == 1)
			return x;
		double res = myPow_Core(x, n >> 1);
		res *= res;
		if (n & 0x1)
			res *= x;
		return res;
	}
};



int main()
{
	Solution a;
	cout << a.myPow(1,INT_MIN) << endl;




	system("pause");
}

