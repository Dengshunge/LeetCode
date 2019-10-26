#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
#include <ctime>
using namespace std;


/*
自己没想出来解题的方法，主要参考网上的方法，解释得很详细
https://www.cnblogs.com/liujinhong/p/5551932.html

从下往上进行修改，从数组相邻元素中选取较小的那个加上这两个元素在上一层的共同相邻元素，这个新值依旧存储在数组中。
这个数组会不断缩小，把最小的值放在前面，当到了第0行之后，最小的值就是数组的收个元素。
*/

class Solution 
{
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		if (triangle.empty())
			return 0;
		int n = triangle.size();
		vector<int> res(triangle.back().begin(),triangle.back().end());
		for (int i = n - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				res[j] = min(res[j], res[j + 1]) + triangle[i][j];
			}
		}
		return res[0];
	}
	
	//
	int minimumTotal2(vector<vector<int>>& triangle) 
	{
		int len = triangle.size();
		vector<vector<int>> res(len, vector<int>(len, INT_MAX));
		res[0][0] = triangle[0][0];
		for (int i = 1; i < len; ++i)
		{
			res[i][0] = res[i - 1][0] + triangle[i][0];
			res[i][i] = res[i - 1][i - 1] + triangle[i][i];
		}
		for (int i = 2; i < len; ++i)
			for (int j = 1; j < i; ++j)
				res[i][j] = min(res[i - 1][j - 1], res[i - 1][j]) + triangle[i][j];
		return *min_element(res.back().begin(), res.back().end());
	}
};


int main() 
{
	Solution a;
	vector<vector<int>> triangle{ {2},{3,4},{6,5,7},{4,1,8,3} };

	auto b = a.minimumTotal(triangle);
	cout << b << endl;


	system("pause");
	return 0;
}
