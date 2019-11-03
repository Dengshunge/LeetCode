#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include "LinearList.cpp"
using namespace std;


class Solution {
public:
	int rob(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		vector<int> dp(nums.size() + 1, 0);
		dp[1] = nums[0];
		for (int i = 2; i <= nums.size(); ++i)
		{
			dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
		}
		return dp.back();
	}

	int rob2(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		if (nums.size() == 1)
			return nums[0];
		vector<int> tmp(nums.begin(), nums.end() - 1);
		int tmp1 = rob(tmp);
		tmp = vector<int>(nums.begin() + 1, nums.end());
		int tmp2 = rob(tmp);
		return max(tmp1, tmp2);
	}
};

int main()
{
	Solution a;
	vector<int> nums{ 2,1 };
	cout << a.rob(nums) << endl;




	system("pause");
	return 0;
}
