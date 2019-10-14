#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
https://leetcode-cn.com/problems/next-permutation/solution/
*/
class Solution {
public:
	void nextPermutation(vector<int>& nums) 
	{
		int length = nums.size();
		int i = length - 1;
		for (; i > 0; --i)
		{
			if (nums[i] > nums[i - 1])
				break;
		}
		// 当指向首元素时，说明都是递增序列，没有更大的序列
		if (i == 0)
		{
			sort(nums.begin(), nums.end());
			return;
		}
		// 此时将i指向需要交换的元素
		--i;
		int j = i;
		while (j < length-1)
		{
			if (nums[i] >= nums[j + 1])
				break;
			++j;
		}
		swap(nums[i], nums[j]);
		sort(nums.begin() + i + 1, nums.end());
	}
};

//
class Solution2 {
public:
 	void nextPermutation(vector<int>& nums) 
	{
		if (nums.size() == 0)
			return;
		int i = nums.size() - 1;
		while (i > 0)
		{
			if (nums[i] > nums[i - 1])
				break;
			i--;
		}
		if (i == 0)
			return reverse(nums.begin(), nums.end());
		int j = i + 1;
		while (j < nums.size())
		{
			if (nums[j] <= nums[i - 1])
				break;
			j++;
		}
		swap(nums[i - 1], nums[j - 1]);
		reverse(nums.begin() + i, nums.end());
	}
};

int main()
{
	vector<int> nums{ 1,5,1 };
	Solution a;
	a.nextPermutation(nums);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;


	system("pause");

}

