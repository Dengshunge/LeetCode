#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
自己的方法，利用数据结构set来进行，时间复杂度是O(nlogn)，空间复杂度是O(n)

本题要求线性时间复杂度，而且不使用额外的复制空间。

当两个数字相同的时候，进行异或就能将两个数字变成0，例如
				1 0 0
				1 0 0
				-----
				0 0 0
所以，当判断两个数字是否相同，可以使用异或
*/


class Solution 
{
public:
	int singleNumber(vector<int>& nums)
	{
		set<int> checkNums;
		for (auto beg = nums.begin(); beg < nums.end(); ++beg)
		{
			auto it = checkNums.find(*beg);
			if (it != checkNums.end())
				checkNums.erase(it);
			else
				checkNums.insert(*beg);
		}
		return *checkNums.begin();
	}
	int singleNumber_network(vector<int>& nums)
	{
		int res = 0;
		for (auto i : nums)
		{
			res ^= i;
		}
		return res;
	}
};


int main() 
{
	Solution a;
	vector<int> nums{ 1,1,2,3,2,3,9 };
	cout << a.singleNumber_network(nums) << endl;


	system("pause");
	return 0;
}
