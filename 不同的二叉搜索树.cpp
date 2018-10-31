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
这种题，就是找规律
第n个数字的组合数，就是有【左边0个，右边n-1个】，【左边1个，右边n-2个】...【左边n-1个，右边0个】组成
左右之间的组合数是乘法结合
*/


class Solution {
public:
	int numTrees(int n) 
	{
		vector<int> table(n + 1, 1);
		for (int i = 2; i <= n; ++i)
		{
			int res = 0;
			for (int j = 1; j <= i; ++j)
			{
				res += table[j - 1] * table[i - j];
			}
			table[i] = res;
		}
		return table.back();
	}
};




int main() 
{
	Solution a;
	cout << a.numTrees(3) << endl;





	system("pause");
	return 0;
}



