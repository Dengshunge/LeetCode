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
最小路径和
和前两题方法一样。
*/

class Solution
{
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		res[0][0] = grid[0][0];
		//初始化
		for (int i = 1; i < n; ++i)
			res[0][i] = res[0][i - 1] + grid[0][i];
		for (int i = 1; i < m; ++i)
			res[i][0] = res[i - 1][0] + grid[i][0];

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				res[i][j] = grid[i][j] + min(res[i][j - 1], res[i - 1][j]);
			}
		}
		return res[m - 1][n - 1];
	}
	
	//update 2019.10.26
	int minPathSum(vector<vector<int>>& grid) 
	{
		int m = grid.size(), n = grid[0].size();
		for (int i = 1; i < n; ++i)
			grid[0][i] += grid[0][i - 1];
		for (int i = 1; i < m; ++i)
			grid[i][0] += grid[i - 1][0];
		for (int i = 1; i<m; ++i)
			for (int j = 1; j < n; ++j)
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		return grid[m - 1][n - 1];
	}
};

int main() 
{
	Solution a;
	vector<vector<int>> grid{ {1,2,5} };
	cout << a.minPathSum(grid) << endl;



	system("pause");
	return 0;
}



