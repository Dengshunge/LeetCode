#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

/*
第一种思路利用count来统计连续出现次数，当nums[right] == nums[right - 1]，判断count是否小于2
	当nums[right] != nums[right - 1]，count归零
第二种思路比较nums[i]是否与nums[k - 2]，当不相等的时候，进行赋值
*/

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() < 3)
			return nums.size();
		int left = 1, right = 1;
		int count = 1;
		while (right < nums.size())
		{
			if (nums[right] == nums[right - 1])
			{
				if (count < 2)
				{
					++count;
					nums[left++] = nums[right];
				}
			}
			else
			{
				count = 1;
				nums[left++] = nums[right];
			}
			++right;
		}
		return left;
	}

	int removeDuplicates2(vector<int>& nums)
	{
		if (nums.size() < 3)
			return nums.size();
		int k = 2;
		for (int i = 2; i < nums.size(); ++i)
		{
			if (nums[i] != nums[k - 2])
				nums[k++] = nums[i];
		}
		return k;
	}

};

int main() 
{
	Solution a;
	vector<int> nums{ 0,0,1,1,1,1,2,3,3 };
	int b = a.removeDuplicates(nums);
	cout << b << endl;
	for (int i = 0; i < b; ++i)
		cout << nums[i] << " ";
	cout << endl;




	system("pause");
	return 0;
}



