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
	int removeDuplicates(vector<int>& nums) 
	{
		if (nums.empty())
			return 0;
		int p1 = 0, p2 = 1;
		while (p2<nums.size())
		{
			while (p2 < nums.size() &&nums[p1] == nums[p2])
				p2++;
			if (p2<nums.size())
				nums[++p1] = nums[p2++];
		}
		return p1 + 1;
	}

	int removeDuplicates2(vector<int>& nums)
	{
		if (nums.size() < 2)
			return nums.size();
		int p1 = 0;
		for (int p2 = 1; p2 < nums.size(); ++p2)
		{
			if (nums[p1] != nums[p2])
				nums[++p1] = nums[p2];
		}
		return p1 + 1;
	}
};


int main()
{
	Solution a;

	vector<int> nums = { 1,2,3,4,5 };
	int b = a.removeDuplicates2(nums);
	cout << b << endl;
	for (auto c : vector<int>(nums.begin(), nums.begin() + b))
		cout << c << " ";
	cout << endl;


	system("pause");
}

