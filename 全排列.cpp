#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
就是全排列问题，伪代码是
if (条件符合)
	将nums压入res中
else
	循环
		交换a,b
		进入迭代
		将a,b换回来
*/

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<vector<int>> res;
		permute_core(nums, res, 0);
		return res;
	}

	void permute_core(vector<int>& nums, vector<vector<int>> &res, int n)
	{
		if (n == nums.size())
		{
			res.push_back(nums);
			return;
		}
		for (int i = n; i < nums.size(); ++i)
		{
			swap(nums[i], nums[n]);
			//这里是将n+1后面的数字进入迭代，不包括本身
			permute_core(nums, res, n + 1);
			swap(nums[i], nums[n]);
		}
	}
};

int main()
{
	vector<int> nums{ 1,2,3 };
	Solution a;
	auto b = a.permute(nums);
	for (auto i : b)
	{
		for (auto m : i)
			cout << m << " ";
		cout << endl;
	}


	system("pause");
}

