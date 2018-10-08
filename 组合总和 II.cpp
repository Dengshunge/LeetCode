#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
与上一题思想几乎一致，上题是迭代是全部数字都再次迭代，而这题是要该数字之后的数字进入迭代。
其次还需要跳过重复的数字。
*/

class Solution
{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		combinationSum2_Core(candidates, target, res, temp);
		return res;
	}

	void combinationSum2_Core(const vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &temp)
	{
		if (target == 0)
		{
			res.push_back(temp);
			return;
		}
		else
		{
			for (auto beg = candidates.begin(); beg != candidates.end(); ++beg)
			{
				if (*beg > target)
					break;
				// 跳过重复的数字，这里需要两个判断条件
				if (beg != candidates.begin() && *beg == *(beg - 1))
					continue;
				temp.push_back(*beg);
				//这里也发生了改动，是beg之后的数字进入迭代。
				combinationSum2_Core(vector<int>(beg + 1, candidates.end()), target - *beg, res, temp);
				temp.pop_back();
			}
		}
	}
};



int main()
{
	vector<int> candidates{ 10,1,2,7,6,1,5 };
	int target = 8;
	Solution b;
	auto a = b.combinationSum2(candidates, target);
	for (auto i : a)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

	system("pause");

}

