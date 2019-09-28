#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> res;
		if (nums.size() < 3)
			//返回空的vector
			return vector<vector<int>>(res.begin(), res.end());
		sort(nums.begin(), nums.end());
		//这里num从[0,nums.size()-2)，因为[nums.size()-2到nums.size()-1只有2个数，不符合3-sum
		for (auto num = nums.begin(); num < nums.end() - 2; ++num)
		{
			if (*num > 0)
				break;
			//跳过重复的数字
			if (num != nums.begin() && *num == *(num - 1))
				continue;
			auto left = num + 1, right = nums.end() - 1;
			while (left<right)
			{
				int tmp = *num + *left + *right;
				if (tmp == 0)
				{
					res.insert({ *num,*left,*right });
					//跳过重复的数字
					//这里不能直接break，因为可能还有其他组合加起来等于0
					while (left < right&&*left == *(left + 1))
						++left;
					++left;
					while (left < right&&*right == *(right - 1))
						--right;
					--right;
				}
				else if (tmp > 0)
					--right;
				else
					++left;
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
	
	//update 2019.9.28
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() && nums[i] <= 0; ++i)
		{
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			for (int left = i+1, right = nums.size()-1; left < right&&nums[right] >= 0;)
			{
				int tmp = nums[left] + nums[right];
				if (tmp == -nums[i])
				{
					res.insert(vector<int>({ nums[i],nums[left],nums[right] }));
					while (left < right&&nums[right] == nums[right - 1])
						right--;
					right--;
					while (left < right&&nums[left] == nums[left + 1])
						left++;
					left++;
				}
				else if (nums[left] + nums[right] > -nums[i])
					--right;
				else
					++left;
			}
			
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};

int main() 
{
	vector<int> nums{1,-1};
	Solution a;
	auto b = a.threeSum(nums);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	


	system("pause");
	return 0;
}
