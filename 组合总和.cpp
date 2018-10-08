#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
采用回溯法。
如果采用回溯法，需要一个条件“什么时候会回溯”。对于这题，当target==0时，可以插入到res中，此时可以回溯，当target<0时，也回溯。
但这里的target<0是通过在for循环中用break来退出循环。
*/

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;
		vector<int> temp;
		sort(candidates.begin(), candidates.end());
		combinationSum_Core(candidates, target, res, temp);
		return res;
	}

	void combinationSum_Core(const vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &temp)
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
				//当值大于target时，由于是有序的，所以退出接下来循环
				if (*beg > target)
					break;
				//将该值压入temp中
				temp.push_back(*beg);
				//循环继续求剩余值
				combinationSum_Core(vector<int>(beg,candidates.end()), target - *beg, res, temp);
				//当到了这一步，说明由此值组成的路径都统计完了，可以将该值弹出了
				temp.pop_back();
			}
		}
	}
};



int main()
{
	vector<int> candidates{ 2,3,5 };
	int target = 8;
	Solution b;
	auto a = b.combinationSum(candidates, target);
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

