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
这里有两种思路
第一种，下标为m的位置能否到达，要看nums[m-i]+m-i是否大于等于m。当大于等于m时，说明可以从m-i的位置直接跳到m的位置。
	然后继续迭代，就有无可以继续跳到m-i的位置。知道m==0时，说明可以从起点到达终点。
第二种，比较第i个位置最远能到底的距离far_reach，当far_reach>=n-1时，说明可以到达终点。

有趣的是，第二种方法的复杂度应该是O(n），应该比第一种快。而实际上在leetcode上跑，是第一种方法快。
*/

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		return canJump_Core(nums, nums.size() - 1);
	}

	bool canJump_Core(vector<int>& nums,int m)
	{
		if (m == 0)
			return true;
		for (int i = 1; i <= m; ++i)
		{
			if (nums[m - i] - i >= 0)
				return canJump_Core(nums, m - i);
		}
		return false;
	}
};

class Solution2
{
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		int far_reach = 0;
		for (int i = 0; i <= far_reach; ++i)
		{
			far_reach = max(far_reach, nums[i] + i);
			if (far_reach >= n - 1)
				return true;
		}
		return false;
	}
};

//update 2019.11.12
class Solution2 {
public:
	bool canJump(vector<int>& nums) 
	{
		int k = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i > k)
				return false;
			k = max(k, i + nums[i]);
			if (k >= nums.size() - 1)
				break;
		}
		return true;
	}
};

class Solution3
{
public:
	bool canJump(vector<int> &nums)
	{
		return helper(nums, 0);
	}
private:
	bool helper(vector<int> &nums, int position)
	{
		if (position == nums.size() - 1)
			return true;
		int furthestJump = min(int(nums.size() - 1), position + nums[position]);
		for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++)
		{
			if (helper(nums, nextPosition))
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums = { 2,3,1,1,4 };
	Solution a;
	cout << boolalpha << a.canJump(nums) << endl;
	


	system("pause");
}

