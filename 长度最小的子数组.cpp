#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>
#include "linearlist.cpp"

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) 
	{
		queue<int> que;
		int que_sum = 0;
		int min_length = INT_MAX, cur_length = 0;
		for (int num : nums)
		{
			que.push(num);
			que_sum += num;
			cur_length++;
			if (que_sum - que.front() >= s)
			{
				while (que_sum - que.front() >= s)
				{
					que_sum -= que.front();
					que.pop();
					cur_length--;
				}
				if (cur_length < min_length)
					min_length = cur_length;
			}
		}
		return (min_length > cur_length) ? 0 : min_length;
	}

	int minSubArrayLen2(int s, vector<int>& nums)
	{
		int min_length = INT_MAX;
		vector<int> sum(nums.size()+1, 0);
		for (int i = 1; i <= nums.size(); i++)
			sum[i] = sum[i - 1] + nums[i - 1];
		for (int i = 1; i < sum.size(); i++)
		{
			int to_find = s + sum[i - 1];
			int left = 0, right = sum.size();
			while (left < right)
			{
				unsigned int mid = (left + right) >> 1;
				if (sum[mid] < to_find)
					left = mid + 1;
				else
					right = mid;
			}
			if (left != sum.size())
				min_length = min(min_length, left - i + 1);
		}
		return (min_length == INT_MAX) ? 0 : min_length;
	}
};



int main()
{
	Solution a;
	
	vector<int> nums = { 2,3,1,2,4,3 };
	cout << a.minSubArrayLen2(0, nums) << endl;


	system("pause");
}

