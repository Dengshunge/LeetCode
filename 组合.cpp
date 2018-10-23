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
类似于全排列的写法；
但网上有种很厉害的写法，用的方法是迭代，暂时没看懂
https://blog.csdn.net/qq_17550379/article/details/82558591
*/

class Solution {
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> res;
		vector<int> path;
		vector<int> table;
		if (k > n)
			return res;
		for (int i = 1; i <= n; ++i)
			table.push_back(i);
		combine(table, res, path, k, 0);
		return res;
	}

	void combine(vector<int> &table, vector<vector<int>> &res, vector<int> &path, int k, int start)
	{
		if (path.size() == k)
		{
			res.push_back(path);
			return;
		}
		for (int i = start; i < table.size() ; ++i)
		{
			path.push_back(table[i]);
			combine(table, res, path, k, i + 1);
			path.pop_back();
		}
	}
};

int main() 
{
	Solution a;
	auto b = a.combine(10,2);
	for (auto m : b)
	{
		for (auto j : m)
			cout << j << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}



