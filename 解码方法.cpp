#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

/*
动态规划，f(n)=p*f(n-1)+q*f(n-2)，当s[n]=='0'时，p=0，否则p=1；当第i和第i-1位组成合法的数字的时候，q=1，否则为0。
当然，前两位需要初始化；
难点就是判断两位数是否合法。

另外有一个将string转成Int的方法：atoi(s.substr(0, 2).data())
s.substr(x,y).data()的类型为const char *
然后利用atoi转换成数字。
*/

class Solution
{
public:
	int numDecodings(string s)
	{
		if (s[0] == '0')
			return 0;
		if (s.size() == 1)
			return 1;
		vector<int> times(s.size(), 0);
		times[0] = 1;
		int temp = (s[0] - '0') * 10 + (s[1] - '0');
		if (s[1] == '0')
		{
			if (temp <= 26)
				times[1] = 1;
		}
		else
		{
			times[1] = (temp <= 26) ? 2 : 1;
		}
		for (int i = 2; i < s.size(); ++i)
		{
			if (s[i] != '0')
				times[i] += times[i - 1];
			temp = (s[i - 1] - '0') * 10 + (s[i] - '0');
			if (temp <= 26 && temp >= 10)
				times[i] += times[i - 2];
		}
		return times.back();
	}
};



int main() 
{
	Solution a;
	cout << a.numDecodings("301") << endl;



	system("pause");
	return 0;
}



