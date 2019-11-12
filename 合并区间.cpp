#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

/*
思路不太难，先根据左端点排序，然后再将下一个的左端点和这个的右端点比较即可。

注意的是：
1.当在类内使用sort函数时，自定义的比较函数需要加上static。否则该自定义函数不能定义在类内。
2.在自定义比较函数时，需要遵循“严格弱序”，即只能是<或者>，不能是是<=或者>=
	https://blog.csdn.net/qq_29883591/article/details/69063253
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
	static bool compare_Interval(const Interval &a, const Interval &b)
	{
		return a.start < b.start;
	}

	vector<Interval> merge(vector<Interval>& intervals) 
	{
		if (intervals.empty())
			return {};
		sort(intervals.begin(), intervals.end(), compare_Interval);
		vector<Interval> res{ intervals[0] };
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (res.back().end >= intervals[i].start)
			{
				res.back().end = max(res.back().end, intervals[i].end);
			}
			else
				res.push_back(intervals[i]);
		}
		return res;
	}
};

//update 2019.11.12
class Solution2 {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		if (intervals.empty())
			return {};
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res{ intervals[0] };
		for (int i = 1; i < intervals.size(); ++i)
		{
			vector<int> &tmp = res.back();
			if (intervals[i][0] <= tmp[1])
				tmp[1] = max(tmp[1], intervals[i][1]);
			else
				res.push_back(intervals[i]);
		}
		return res;
	}
};

int main()
{
	vector<Interval> x{ { 1,3 },{ 1,6 },{ 8,10 },{ 15,18 } };
	Solution a;
	auto b = a.merge(x);
	for (auto i : b)
	{
		cout << i.start << ":" << i.end << " ";
	}
	cout << endl;

	


	system("pause");
}


