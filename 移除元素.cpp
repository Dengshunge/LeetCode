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
	int removeElement(vector<int>& nums, int val) 
	{
		int i = 0;
		for (int j = i; j < nums.size(); ++j)
		{
			if (nums[j] != val)
				nums[i++] = nums[j];
		}
		return i;
	}
};


int main()
{
	Solution a;

	vector<int> nums = { 1};
	int b = a.removeElement(nums,1);
	cout << b << endl;
	for (auto c : vector<int>(nums.begin(), nums.begin() + b))
		cout << c << " ";
	cout << endl;


	system("pause");
}

