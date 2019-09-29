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
	
	//update 2019.3.18
	int threeSumClosest2(vector<int>& nums, int target)
	{
		int res = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i<len - 2; ++i)
		{
			for (int m = i + 1, n = len - 1; m<n;)
			{
				int tmp = nums[i] + nums[m] + nums[n];
				if (abs(target - res)>abs(target - tmp))
					res = tmp;
				if (target>tmp)
					++m;
				else if (target<tmp)
					--n;
				else
					//break;
					//不需要break了，两者相等时，是最小的，所以返回target即可
					return target;
			}
		}
		return res;
	}
	
	//update 2019.9.29
	int threeSumClosest3(vector<int>& nums, int target) 
	{
		int min_sum = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (auto iter = nums.begin(); iter < nums.end(); ++iter)
		{
			if (iter != nums.begin() && *iter == *(iter - 1))
				continue;
			for (auto left = iter + 1, right = nums.end() - 1; left < right;)
			{
				int tmp = *iter + *left + *right - target;
				if (abs(tmp) < abs(min_sum - target))
					min_sum = *iter + *left + *right;
				if (tmp == 0)
					return min_sum;
				else if (tmp > 0)
					right--;
				else
					left++;
			}
		}
		return min_sum;
	}
};

int main()
{
	Solution a;
	vector<int> x{1,1,1,1};
	cout << a.threeSumClosest(x, 0) << endl;





	system("pause");

}

