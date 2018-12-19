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
当prices[i] > prices[i - 1]说明还能获利，最大利润往上加；
当prices[i] < prices[i - 1]说明股票应该全部卖出去，重新在第i天买新的。
*/

class Solution 
{
public:
	int maxProfit(vector<int>& prices)
	{
		int maxVal = 0;
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i] > prices[i - 1])
			{
				maxVal += prices[i] - prices[i - 1];
			}
		}
		return maxVal;
	}
};


int main() 
{
	Solution a;
	vector<int> prices{ 5,4,3,2,1 };

	auto b = a.maxProfit(prices);
	cout << b << endl;


	system("pause");
	return 0;
}
