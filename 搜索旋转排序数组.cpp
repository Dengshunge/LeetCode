#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
思路是先寻找最小点，也就是旋转的点，然后判断是从旋转点的前面还是后面开始查找。
这里查找可以用二分查找，这样复杂度就是O(log n)
*/
class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		int length = nums.size();
		if (length <= 0)
			return -1;
		int left = 0, right = length - 1;
		int mid = 0;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;
		}
		mid = left;
		if (mid == 0)
			return two_find(nums, 0, length - 1, target);
		else if (nums[0] <= target)
			return two_find(nums, 0, mid - 1, target);
		else
			return two_find(nums, mid, length - 1, target);
	}

	int two_find(vector<int> &nums, int left, int right,int target)
	{
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}
};

int main()
{
	vector<int> nums{ 3,1 };
	Solution a;
	cout << a.search(nums, 1) << endl;


	system("pause");

}

