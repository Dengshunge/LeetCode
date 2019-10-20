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
	int findMin(vector<int>& nums) 
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			unsigned int mid = (left + right) >> 1;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;
		}
		return nums[left];
	}
};

int main()
{
	Solution a;
	vector<int> nums = { 4,5,6,7,0,1,2 };
	cout << a.findMin(nums) << endl;




	system("pause");
	return 0;
}
