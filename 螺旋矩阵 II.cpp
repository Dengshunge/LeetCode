#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		if (n <= 0)
			return {};
		vector<vector<int>> res(n, vector<int>(n,0));
		int key = 1;
		for (int i = 0; i < n / 2; ++i)
		{
			//左->右
			for (int j = i; j < n - 1 - i; ++j)
				res[i][j] = key++;
			//上->下
			for (int j = i; j < n - 1 - i; ++j)
				res[j][n - 1 - i] = key++;
			//右->左
			for (int j = n - 1 - i; j > i; --j)
				res[n - 1 - i][j] = key++;
			//下->上
			for (int j = n - 1 - i; j > i; --j)
				res[j][i] = key++;
		}
		if (n & 0x1)
			res[n / 2][n / 2] = key;
		return res;
	}
};

int main() 
{
	int n = 400;
	Solution a;
	auto b = a.generateMatrix(n);
	for (auto i : b)
	{
		for (auto m : i)
			cout << m << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}



