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
有两种方法：
第一种，暴力法，即回溯法，当这种方法会超时；
第二种，找规律，如果要到达(m,n)，则是到达(m-1,n)和(m,n-1)的路径之和。
	所以先弄一张res[m][n]大小的表格，然后第一行和第一列都是1，之后计算每个点的路径即可。
	但这道题有个bug，当100*100的时候，会返回负数，我认为是越界了，这里还应该考虑大数问题。
*/

class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		int count = 0;
		uniquePaths_Core(m, n, 1, 1, count);
		return count;
	}

	void uniquePaths_Core(int m, int n, int x, int y, int &count)
	{
		if (x == m && y == n)
		{
			++count;
			return;
		}
		if (x < m)
			uniquePaths_Core(m, n, x + 1, y, count);
		if (y < n)
			uniquePaths_Core(m, n, x, y + 1, count);
	}
};

class Solution2
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> res(m, vector<int>(n, 0));
		//初始化
		for (int i = 0; i < n; ++i)
			res[0][i] = 1;
		for (int i = 0; i < m; ++i)
			res[i][0] = 1;
		//res[m][n]=res[m-1][n]+res[m][n-1]
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				res[i][j] = res[i][j - 1] + res[i - 1][j];
			}
		}
		return res[m - 1][n - 1];
	}
	
	//update 2019.10.29
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i<m; i++)
			for (int j = 1; j<n; ++j)
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		return dp[m - 1][n - 1];
	}
};

int main() 
{
	Solution2 a;
	int x, y;
	while (true)
	{
		cin >> x >> y;
		cout << a.uniquePaths(x, y) << endl;
	}

	system("pause");
	return 0;
}



