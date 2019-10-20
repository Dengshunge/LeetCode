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
	int search(vector<int>& nums, int target) 
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			unsigned int mid = (left + right) >> 1;
			if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (nums[left] == target)
			return left;
		return -1;
	}
};

int main()
{
	Solution a;
	vector<int> nums = { -1,0,3,5,9,12 };
	cout << a.search(nums, 0) << endl;







	system("pause");
	return 0;
}
