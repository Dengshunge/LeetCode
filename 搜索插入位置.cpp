#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

class Solution
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int low = 0, high = nums.size() - 1;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) >> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		if (nums[mid] > target)
		{
			nums.insert(nums.begin() + mid, target);
			return mid;
		}
		else
		{
			nums.insert(nums.begin() + mid + 1, target);
			return mid + 1;
		}
	}
};



int main()
{
	vector<int> nums{ 1,3,5,6 };
	Solution a;
	cout << a.searchInsert(nums, 0) << endl;


	system("pause");

}

