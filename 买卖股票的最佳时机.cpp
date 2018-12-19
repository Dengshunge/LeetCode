#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
先定义函数diff(i)为当卖出价为数组中的第i个数字时可能获得的最大利润。当卖出价固定是，买入价越低，则利润越大。
即扫描到数组中第i个数字时，只要记住之前i-1个数字中的最小值，就能算出当前价位卖出的最大利润。
*/

class Solution 
{
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() < 2)
			return 0;
		int min = prices[0];
		int maxVal = prices[1] - min;
		for (int i = 2; i < prices.size(); ++i)
		{
			if (prices[i - 1] < min)
				min = prices[i - 1];
			int cur = prices[i] - min;
			if (cur > maxVal)
				maxVal = cur;
		}
		return maxVal > 0 ? maxVal : 0;
	}
};


int main() 
{
	Solution a;
	vector<int> prices{ 7,1,5,3,6,4 };

	auto b = a.maxProfit(prices);
	cout << b << endl;


	system("pause");
	return 0;
}
