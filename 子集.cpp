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
就是全排列的变式
*/

class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res;
		vector<int> path;
		subsets(nums, res, path, 0);
		return res;
	}

	void subsets(vector<int>& nums, vector<vector<int>> &res, vector<int> &path, int start)
	{
		res.push_back(path);
		for (int i = start; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);
			subsets(nums, res, path, i + 1);
			path.pop_back();
		}
	}
};

int main() 
{
	Solution a;
	vector<int> nums{ 1,2,3 };
	auto b = a.subsets(nums);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
