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
思路就是顺时针压入，控制好下标就行。
值得注意的是，需要在从右到左和从下到上需要判断是否已经重复过。
*/

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		if (m == 0)
			return {};
		int n = matrix[0].size();
		vector<int> res;
		for (int i = 0; i <= (min(m, n) - 1) / 2; ++i)
		{
			//左->右
			for (int j = i; j < n - i; ++j)
				res.push_back(matrix[i][j]);
			//上->下
			for (int j = i + 1; j < m - i; ++j)
				res.push_back(matrix[j][n - 1 - i]);
			//右->左
			if (i >= m - 1 - i)
				break;
			for (int j = n - 2 - i; j >= i; --j)
				res.push_back(matrix[m - 1 - i][j]);
			//下->上
			if (i >= n - 1 - i)
				break;
			for (int j = m - 2 - i; j > i; --j)
				res.push_back(matrix[j][i]);
		}
		return res;
	}
};



int main()
{
	vector<vector<int>> nums = { { 2,5 },
	{ 8,4 },
	{ 0, -1 }
	};
	Solution a;
	auto b = a.spiralOrder(nums);
	for (auto i : b)
		cout << i << " ";
	cout << endl;


	system("pause");
}

