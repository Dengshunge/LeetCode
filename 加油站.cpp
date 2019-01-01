#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
#include <numeric>
using namespace std;

/*
第一种方法是暴力方法，判断从每个位置开始，能否回到原点，此时需要一个辅助函数来进行判断，时间复杂度是O(n^2)
第二种方法是网上的方法
https://www.cnblogs.com/MrSaver/p/9644679.html
https://blog.csdn.net/DERRANTCM/article/details/47678215
令dif[i]=gas[i]-cost[i]，假设从i能到达k点，则dif[i]+dif[i+1]+...+dif[k]>=0，并且从i点不能到达k+1点，则dif[i]+dif[i+1]+...+dif[k]+dif[k+1]<0。
此时我们应该从k+1点开始新的遍历。因为dif[i]>=0，如果从i+1点开始，则dif[i+1]+...+dif[k]+dif[k+1]的值只会更小。
同理从i点能到i+2点，说明dif[i]+dif[i+1]+dif[i+2]>=0.如果从i+2点开始，则dif[i+2]+...+dif[k]+dif[k+1]的值也只会更小。
所以应该从k+1点开始。

如果i点不能到达p点，则sum1=dif[i]+...+dif[p]<0。
则从p+1点开始，如果p+1点不能到达q点，则sum2=dif[p+1]+...+dif[q]<0.
则从q+1点开始，如果q+1点能到达k点，则sum3=dif[q+1]+...+dif[k]>=0.
现在判断q+1点能否回到q点，则判断sum1+sum2+sum3是否大于等于0
*/


class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0))
			return -1;
		int start = 0, end = gas.size();
		while (start < end)
		{
			while (start < end&&gas[start] < cost[start])
				++start;
			if (canCompleteCircuit(gas, cost, start, end))
				return start;
			++start;
		}
		return -1;
	}

	int canCompleteCircuit_network(vector<int>& gas, vector<int>& cost)
	{
		int tank = 0, total = 0, result = 0;
		for (int i = 0; i < gas.size(); ++i)
		{
			tank += gas[i] - cost[i];
			if (tank < 0)
			{
				result = i + 1;
				total += tank;
				tank = 0;
			}
		}
		return (total + tank < 0) ? -1 : result;
	}

private:
	bool canCompleteCircuit(vector<int>& gas, vector<int>& cost, int start,int end)
	{
		int odd = gas[start] - cost[start];
		int beg = (start + 1 < end) ? start + 1 : 0;
		while (beg != start)
		{
			if (odd < 0)
				return false;
			odd = odd + gas[beg] - cost[beg];
			beg = (++beg) % end;
		}
		return true;
	}
};


int main() 
{
	vector<int> gas{ 2,3,4 };
	vector<int> cost{ 3,4,3 };
	Solution a;
	cout << a.canCompleteCircuit(gas, cost) << endl;


	system("pause");
	return 0;
}
