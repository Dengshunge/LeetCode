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
第一种，先对行进行二分搜索，找到所在行，再对列进行二分搜索，时间复杂度是O(logm+logn)
第二种，将其认为是一维数组，每次与中间值比较，时间复杂度是O(log m*n)
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		if (matrix[0][0] > target)
			return false;
		int low = 0, high = m - 1;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) >> 1;
			if (matrix[mid][0] == target || matrix[mid][n - 1] == target)
				return true;
			if (matrix[mid][0] < target && matrix[mid][n - 1] > target)
				break;
			else if (matrix[mid][0] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}

		int col = mid;
		low = 0, high = n - 1;
		while (low <= high)
		{
			mid = (low + high) >> 1;
			if (matrix[col][mid] == target)
				return true;
			else if (matrix[col][mid] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}

	bool searchMatrix2(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		int low = 0, high = m*n - 1;
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			//这一这里下标的表达
			if (matrix[mid / n][mid%n] == target)
				return true;
			else if (matrix[mid / n][mid%n] > target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}
};

int main() 
{
	Solution a;
	vector<vector<int>> matrix{ { 1,   3,  5,  7 },
	{ 10, 11, 16, 20 },
	{ 23, 30, 34, 50 } };
	int i;
	while (cin>>i)
	{
		cout << boolalpha << a.searchMatrix2(matrix, i) << endl;
	}


	system("pause");
	return 0;
}



