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
	int findPeakElement(vector<int>& nums) 
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			unsigned int mid = (left + right) >> 1;
			if (nums[mid] > nums[mid + 1])
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};



int main()
{
	Solution a;
	
	vector<int> nums = { 1 };
	cout << a.findPeakElement(nums) << endl;


	system("pause");
}

