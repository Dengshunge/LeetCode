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
有三种方法
第一种：统计0,1,2出现的次数，然后在原数组上进行修改。
第二种：left指向0，right指向2，当nums[i]遇到0的时候，就交换swap(nums[i], nums[left])，然后left前移
第三种：i，j，k分别指向当前已处理好的字符串的最后一个0，1，2，m代表需要处理的数字，详情见帖子


https://www.cnblogs.com/ganganloveu/p/3703746.html
https://blog.csdn.net/twt727/article/details/80101396
*/

class Solution {
public:
	void sortColors(vector<int>& nums) 
	{
		vector<int> table(3, 0);
		for (auto iter = nums.begin(); iter < nums.end(); ++iter)
		{
			++table[*iter];
		}
		auto iter = nums.begin();
		for (int times = 0; times<3; ++times)
		{
			for (int i = table[times]; i > 0; --i,++iter)
			{
				*iter = times;
			}
		}
	}

	void sortColors2(vector<int>& nums)
	{
		int left = 0, right = nums.size() - 1;
		int i = 0;
		while (i <= right)
		{
			if (nums[i] == 0)
			{
				swap(nums[i], nums[left]);
				++i;
				++left;
			}
			else if (nums[i] == 2)
			{
				swap(nums[i], nums[right]);
				++i;
				--right;
			}
			else
				++i;
		}
	}
	
	void sortColors3(vector<int>& nums)
	{
		int i = -1, j = -1, k = -1;//i，j，k分别指向当前已处理好的字符串的最后一个0，1，2
		for (int m = 0; m < nums.size(); ++m)
		{
			if (nums[m] == 0)
			{
				nums[++k] = 2;
				nums[++j] = 1;
				nums[++i] = 0;
			}
			else if (nums[m] == 1)
			{
				nums[++k] = 2;
				nums[++j] = 1;
			}
			else
				nums[++k] = 2;
		}
	}

};

//
class Solution2 {
public:
	void sortColors(vector<int>& nums) 
	{
		vector<int> times(3, 0);
		for (auto num : nums)
			times[num] += 1;
		int index = 0;
		for (int i = 0; i < times.size(); ++i)
		{
			for (int j = 0; j < times[i]; ++j)
				nums[index++] = i;
		}
	}

	void sortColors2(vector<int>& nums)
	{
		int p0 = 0, p2 = nums.size() - 1, cur = 0;
		while (cur <= p2)
		{
			if (nums[cur] == 0)
				swap(nums[cur++], nums[p0++]);
			else if (nums[cur] == 2)
				swap(nums[cur], nums[p2--]);//注意，这里cur没有自增，因为不确定交换后是否条件
			else
				cur++;
		}
	}
};
int main() 
{
	Solution a;
	vector<int> nums{ 2,0,2,1,1,0 };
	a.sortColors2(nums);
	for (auto i : nums)
		cout << i << " ";
	cout << endl;

	system("pause");
	return 0;
}



