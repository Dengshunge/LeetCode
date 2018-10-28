#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;


/*
这不是一道回溯法的题目，因为在如果使用回溯法，1001的下一个是0100，
不符合题目要求（连续两位只能变动一位）。
所以这道题需要找规律，可以发现n=k时，其n-1位的数字是n=k的上下景象
这道题的规律不太好找，可以参考https://blog.csdn.net/u012501459/article/details/46790683

另外，格雷码是存在数学公式计算的，但这里不考虑这种方法，如果遇到，可以直接使用数学公式。
*/
class Solution {
public:
	vector<int> grayCode(int n)
	{
		vector<int> res{ 0 };
		for (int i = 0; i < n; ++i)
		{
			for (int j = res.size() - 1; j >= 0; --j)
			{
				res.push_back((1 << i) + res[j]);
			}
		}
		return res;
	}
};


int main()
{
	Solution a;
	const int n = 4;
	vector<int> res = a.grayCode(n);
	for (auto i : res)
	{
		cout << i << " ";
		cout << bitset<n>(i) << endl;
	}



	
	system("pause");
}

