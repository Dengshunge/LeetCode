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
和上一题一样的方法，不同的是，在初始化第一行和第一列的时候，如果前面遇到1，则后面都是0。
*/

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		vector<vector<int>> res(m, vector<int>(n, 0));
		//初始化
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (flag && (obstacleGrid[0][i] == 0))
				res[0][i] = 1;
			else
			{
				flag = false;
				res[0][i] = 0;
			}
		}
		flag = true;
		for (int i = 0; i < m; ++i)
		{
			if (flag && (obstacleGrid[i][0] == 0))
				res[i][0] = 1;
			else
			{
				flag = false;
				res[i][0] = 0;
			}
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (obstacleGrid[i][j] == 0)
					res[i][j] = res[i][j - 1] + res[i - 1][j];
			}
		}
		return res[m - 1][n - 1];
	}

        //update 2019.10.29
	int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) 
	{
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		if (obstacleGrid[0][0])
			return 0;
		vector<vector<long long>> dp(m, vector<long long>(n, 1));
		int i = 1;
		for (; i < n; ++i)
			if (obstacleGrid[0][i])
				break;
		for (; i < n; i++)
			dp[0][i] = 0;
		i = 1;
		for (; i < m; ++i)
			if (obstacleGrid[i][0])
				break;
		for (; i < m; i++)
			dp[i][0] = 0;
		for (int i = 1; i<m; ++i)
			for (int j = 1; j < n; ++j)
				dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];
		return dp[m - 1][n - 1];
	}
};

int main() 
{
	Solution a;
	vector<vector<int>> obstacleGrid{ {0},{0} };
	cout << a.uniquePathsWithObstacles(obstacleGrid) << endl;



	system("pause");
	return 0;
}



