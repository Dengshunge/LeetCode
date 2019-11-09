#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*旋转图像
有两种方法：
第一种，寻找交换下标的规律，直接交换，可以得到[i,j]->[j,n-1-i]这样的规律。将这样的坐标交换三次，就能得到最终结果。
第二种，先将矩阵转置（即按对角线来对称），然后将每行矩阵逆序（按中位线对称），就能得到顺时针旋转90度的结果。这种方法类似于数学上的转置后对称。
*/

class Solution
{
public:
	void rotate(vector<vector<int>>& matrix)
	{
		int n = matrix.size();
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = i; j < n - 1 - i; ++j)
			{
				swap(matrix[i][j], matrix[j][n - 1 - i]);
				swap(matrix[i][j], matrix[n - 1 - i][n - 1 - j]);
				swap(matrix[i][j], matrix[n - 1 - j][i]);
			}
		}
	}
};

class Solution2 {
public:
	// 先转置，后逆序，就能得到顺时针旋转90度的矩阵
	void rotate(vector<vector<int>>& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row - 1; i++) {
			for (int j = i + 1; j < col; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < row; i++) reverse(matrix[i].begin(), matrix[i].end());
	}
};

//
class Solution3 {
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int size = matrix.size();
		for (int i = 0; i < size; ++i)
		{
			for (int j = i; j < size; ++j)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < size; ++i)
		{
			reverse(matrix[i].begin(), matrix[i].end());
		}
	}
};

int main()
{
	vector<vector<int>> matrix{ {1,2,3},{4,5,6},{7,8,9} };
	for (auto i : matrix)
	{
		for (auto x : i)
			cout << x << " ";
		cout << endl;
	}

	cout << endl;

	Solution a;
	a.rotate(matrix);
	for (auto i : matrix)
	{
		for (auto x : i)
			cout << x << " ";
		cout << endl;
	}


	system("pause");
}

