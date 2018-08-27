#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 类似于上一题的三数之和，同样是设置双指针。
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		if (nums.empty())
			return INT_MIN;
		sort(nums.begin(), nums.end());
		int res = nums[0];
		int gap = INT_MAX;
		int length = nums.size();
		for (int i = 0; i < length; ++i)
		{
			//跳过重复的数字
			if (i && nums[i] == nums[i - 1])
				continue;
			int left = i + 1, right = length - 1;
			while (left < right)
			{
				int temp = nums[i] + nums[left] + nums[right];
				int dif = abs(temp - target);
				if (dif < gap)
				{
					gap = dif;
					res = temp;
				}
				//移动双指针
				if (left < right && temp < target)
				{
					while (left < right && nums[left] == nums[left + 1])
						++left;
					++left;
				}
				if (left < right && temp > target)
				{
					while (left < right && nums[right] == nums[right - 1])
						--right;
					--right;
				}
				if (left < right && temp == target)
				{
					return res;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution a;
	vector<int> x{1,1,1,1};
	cout << a.threeSumClosest(x, 0) << endl;





	system("pause");

}

