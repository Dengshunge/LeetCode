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
此题是找规律，我用了递归的方法，效率还可以，但代码有些复杂
网上有更加直接的方法
https://www.cnblogs.com/jdneo/p/5305212.html
*/
class Solution {
public:
	string getPermutation(int n, int k) 
	{
		string res;
		for (int i = 1; i <= n; ++i)
			res += to_string(i);
		getPermutation_Core(res, 0, jiecheng(n - 1), k);
		return res;
	}

	//n代表下一个的阶乘数
	//1+{2,3,4},n代表{2,3,4}三个数的阶乘，表示有多少种排列方式
	void getPermutation_Core(string &s1, int start, int n, int k)
	{
		if (k <= 1)
			return;
		int i = 0;
		while (i + n < k)
			i += n;
		swap(s1[start], s1[start + i / n]);
		// 将其整理有序，可以理解为排序，但这个if的时间复杂度只有o(n)，所以比排序算法快一点
		if (i != 0)
		{
			int index = start + i / n;
			char temp = s1[index];
			for (; index > start+1; --index)
			{
				s1[index] = s1[index - 1];
			}
			s1[index] = temp;
		}
		// 处理下一步
		getPermutation_Core(s1, start + 1, jiecheng(s1.size() - start - 2), k - i);
	}

	int jiecheng(int n)
	{
		int res = n;
		for (int i = n - 1; i > 0; --i)
		{
			res *= i;
		}
		return res;
	}
};

int main() 
{
	Solution a;
	cout << a.getPermutation(4, 2) << endl;



	system("pause");
	return 0;
}



