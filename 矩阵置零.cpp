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
有几种方法可以解决
第一种，创建一个与matrix同样的矩阵，标志matrix为0的位置，最后统一修改，这样空间复杂度是O(mn)
第二种，创建一个大小为m和大小为n的矩阵，分别表示哪一行和哪一列需要全部置为0，空间复杂度是O(m+n)
第三种，创建两个标志位，表示第一行和第一列是否最后需要置0；然后从点(1,1)开始读取，遇到0，则将matrix[i][0]和matrix[0][j]值0，这样就知道哪些行列需要置0,。
	最后读取最先的两个标志位，修改第一行和第一列。空间复杂度是O(1)

第二种方法比第三种方法跑得更加快。
*/

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) 
	{
		int m = matrix.size(), n = matrix[0].size();
		vector<int> row(n, 1);//列
		vector<int> col(m, 1);//行
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					row[j] = 0;
					col[i] = 0;
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (row[i] == 0)
			{
				for (int j = 0; j < m; ++j)
				{
					matrix[j][i] = 0;
				}
			}
		}

		for (int i = 0; i < m; ++i)
		{
			if (col[i] == 0)
			{
				for (int j = 0; j < n; ++j)
				{
					matrix[i][j] = 0;
				}
			}
		}
	}

	void setZeroes2(vector<vector<int>>& matrix)
	{
		int m = matrix.size(), n = matrix[0].size();
		bool col = false, row = false;
		for (int i = 0; i < n; ++i)
		{
			if (matrix[0][i] == 0)
			{
				col = true;
				break;
			}
		}
		for (int i = 0; i < m; ++i)
		{
			if (matrix[i][0] == 0)
			{
				row = true;
				break;
			}
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
				{
					matrix[i][j] = 0;
				}
			}
		}


		if (col)
		{
			for (int i = 0; i < n; ++i)
			{
				matrix[0][i] = 0;
			}
		}
		if (row)
		{
			for (int i = 0; i < m; ++i)
			{
				matrix[i][0] = 0;
			}
		}

	}
};

int main() 
{
	Solution a;
	vector<vector<int>> matrix{ { 0,1,2,0 },
	{ 3,4,5,2 },
	{ 1,3,1,5 } };
	a.setZeroes2(matrix);
	for (auto i : matrix)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}



