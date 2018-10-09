#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
此题比上一题多了一个条件，元素会重复，例如[1,1,2]，会重复交换第1个1和第2个1.
此时需要加入一个判断条件，判断该元素是否在之前出现过，详情见下面的判断条件
*/

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> res;
		permuteUnique_core(nums, res, 0);
		return res;
	}

	void permuteUnique_core(vector<int>& nums, vector<vector<int>> &res, int n)
	{
		if (n == nums.size())
		{
			res.push_back(nums);
			return;
		}
		for (int i = n; i < nums.size(); ++i)
		{
			if (!check_same(nums, n, i - 1, i))
				continue;
			swap(nums[i], nums[n]);
			permuteUnique_core(nums, res, n + 1);
			swap(nums[i], nums[n]);
		}
	}
	
	//判断nums[targe]是否在nums[start]到nums[end]之间出现过，当出现过，就不再交换
	//因为之前的元素交换完后，才会轮到nums[targe]，所以当nums[targe]出现过，说明之前已经交换过
	bool check_same(vector<int>& nums, int start, int end, int target)
	{
		for (int i = start; i <= end; ++i)
		{
			if (nums[i] == nums[target])
				return false;
		}
		return true;
	}
};

int main()
{
	vector<int> nums{ 1,1,3,3 };
	Solution a;
	auto b = a.permuteUnique(nums);
	for (auto i : b)
	{
		for (auto m : i)
			cout << m << " ";
		cout << endl;
	}


	system("pause");
}

