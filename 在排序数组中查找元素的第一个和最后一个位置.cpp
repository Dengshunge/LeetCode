#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Solution
{
//这是我自己写的版本，感觉写的有点复杂
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		int length = nums.size();
		if (length < 1 || target<nums.front() || target>nums.back())
			return { -1,-1 };
		int left = 0, right = length - 1;
		int mid = 0;
		int begin = 0, end = 0;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] == target)
			{
				if (mid == 0 || (mid > 0 && nums[mid - 1] != target))
					break;
				right = mid - 1;
			}
			else if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (nums[mid] != target)
			return { -1,-1 };
		else
			begin = mid;
		//找结尾
		right = length - 1;
		while (left <= right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] == target)
			{
				if (mid == length || (mid < length - 1 && nums[mid + 1] != target))
					break;
				left = mid + 1;
			}
			else 
				right = mid - 1;
		}
		end = mid;
		return { begin,end };
		
	}
};

class Solution2
{
public:
	int binary_search(vector<int> &nums, int target, bool flag)
	{
		//注意，这里high= nums.size()，不减1是因为当元素最后出现的时候，返回的是length，而不是length-1
		int low = 0, high = nums.size() ;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			//当寻找左边界的时候，flag=true，此时当nums[mid]>=target时，high==mid
			//这里不再比较nums[mid-1]，因为这里是比较当low==high时，说明就是左边界
			if (nums[mid] > target || (flag && nums[mid] == target))
				high = mid;
			else
				low = mid + 1;
		}
		return low;
	}

	vector<int> searchRange(vector<int>& nums, int target)
	{
		int length = nums.size();
		if (length < 1 || target<nums.front() || target>nums.back())
			return { -1,-1 };
		int left = binary_search(nums, target, true);
		if (nums[left] != target)
			return { -1,-1 };
		return { left,binary_search(nums,target,false) - 1 };
	}
};


int main()
{
	vector<int> nums{ 5,7,7,8,8,10 };
	int target = 9;
	//Solution a;
	//auto b = a.searchRange(nums, target);
	//for (auto i : b)
	//	cout << i << endl;

	Solution2 a;
	auto b = a.searchRange(nums, target);
	for (auto i : b)
		cout << i << endl;

	system("pause");
	return 0;
}
