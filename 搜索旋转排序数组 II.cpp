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
升级版，与之前不重复的版本的方法不同
之前用的方法是找到旋转点，但此方法会有点复杂。

https://yq.aliyun.com/articles/3888
*/

class Solution
{
public:
	bool search(vector<int>& nums, int target) 
	{
		int length = nums.size();
		int left = 0, right = length - 1;
		while (left <= right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return true;
			if (nums[mid] > nums[left])
			{
				//说明[left,mid]之间的序列是升序的
				if (target >= nums[left] && target <= nums[mid])
				{
					//当target位于前半部分
					right = mid - 1;
				}
				else
					left = mid + 1;
			}
			else if (nums[mid] < nums[left])
			{
				if (target >= nums[mid] && target <= nums[right])
				{
					left = mid + 1;
				}
				else
					right = mid - 1;
			}
			else
			{
				++left;
			}
		}
		return false;
	}
};


int main() 
{
	Solution a;
	vector<int> nums{ 1,3 };
	int n = 0;
	while (cin >> n)
	{
		cout << boolalpha << a.search(nums, n) << endl;
	}
	/*cout << boolalpha << a.search(nums, 1) << endl;*/


	system("pause");
	return 0;
}



