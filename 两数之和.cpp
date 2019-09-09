#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		if (nums.empty())
		{
			return {};
		}
		map<int, int> dif_index;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (dif_index.find(nums[i]) != dif_index.end())
				return { dif_index.find(nums[i])->second,i };
			else
			{
				dif_index[target - nums[i]] = i;
			}
		}
	}
};


int main()
{
	Solution a;

	vector<int> nums = { 2, 7, 11, 15 };
	auto b = a.twoSum(nums, 9);
	for (auto c : b)
	{
		cout << c << " ";
	}
	cout << endl;


	system("pause");
}

