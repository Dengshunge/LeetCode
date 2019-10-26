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

class Solution {
public:
	int climbStairs(int n) 
	{
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		vector<int> res{ 1,2 };
		for (int i = 3; i <= n; ++i)
		{
			int temp = *(res.end() - 1) + *(res.end() - 2);
			res.push_back(temp);
		}
		return res.back();
	}
	
	//update 2019.10.26
	int climbStairs2(int n) 
	{
		if (n == 1 || n == 2)
			return n;
		vector<int> res(n + 1, 0);
		res[1] = 1;
		res[2] = 2;
		for (int i = 3; i <= n; ++i)
		{ 
			res[i] = res[i - 1] + res[i - 2];
		}
		return res.back();
	}
};

int main() 
{
	Solution a;
	cout << a.climbStairs(4) << endl;


	system("pause");
	return 0;
}



