#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


/*
这题有重复元素出现，所以可以使用set这种数据类型，让编译器自动去除重复的元素。
*/
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		set<vector<int>> res;
		vector<int> path;
		sort(nums.begin(), nums.end());
		subsetsWithDup(nums, res, path, 0);
		return vector<vector<int>>(res.begin(),res.end());
	}

	void subsetsWithDup(vector<int>& nums, set<vector<int>> &res, vector<int> &path, int start)
	{
		res.insert(path);
		for (int i = start; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);
			subsetsWithDup(nums, res, path, i + 1);
			path.pop_back();
		}
	}
};


int main()
{
	Solution a;
	vector<int> nums{ 1,2,2 };
	auto res = a.subsetsWithDup(nums);
	for (auto m : res)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}




	
	system("pause");
}

