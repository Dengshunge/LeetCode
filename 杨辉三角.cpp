#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
自己使用的方法，因为没有预先分配好大小，所以可能会导致vector会不断复制移动
而网上的方法是实现分配好vector的大小
这里要复习一下resize的用法
resize(int n,type val)
当n大于原始vector分配的大小的时候，会将vector的大小扩展到n，并使用val来填充扩展部分的内容；
当n小于原始vector分配的大小的时候，会将vector的大小收缩到n，并将多余的部分删除。
*/

class Solution 
{
public:
	vector<vector<int>> generate(int numRows) 
	{
		if (numRows == 0)
			return {};
		if (numRows == 1)
			return { {1} };
		vector<vector<int>> res = { {1},{1,1} };
		if (numRows == 2)
			return res;
		for (int i = 3; i <= numRows; ++i)
		{
			vector<int> path{ 1 };
			for (int j = 1; j < i - 1; ++j)
			{
				path.push_back(res.back()[j - 1] + res.back()[j]);
			}
			path.push_back(1);
			res.push_back(path);
		}
		return res;
	}

	vector<vector<int>> generate_network(int numRows)
	{
		vector<vector<int>> res;
		res.resize(numRows);
		for (int i = 1; i <= numRows; ++i)
		{
			res[i - 1].resize(i, 0);//调整大小
			res[i - 1][0] = 1;//将本行的首尾调成1
			res[i - 1][i - 1] = 1;
		}
		for (int i = 2; i < numRows; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
		}
		return res;
	}
};


int main() 
{
	Solution a;
	auto b = a.generate(5);
	for (auto m : b)
	{
		for (auto n : m)
		{
			cout << n << " ";
		}
		cout << endl;
	}




	system("pause");
	return 0;
}
