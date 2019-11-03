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
};

int main()
{
	Solution a;
	vector<int> nums{ 2,1 };
	cout << a.rob(nums) << endl;




	system("pause");
	return 0;
}
