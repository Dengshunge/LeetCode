#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
	int reverse(int x) {
		bool flag = (x >= 0) ? true : false;
		int res = 0;
		while (x != 0)
		{
			int tmp = x % 10;
			if ((flag && (res>(INT_MAX - tmp) / 10)) || (!flag && (res<(INT_MIN - tmp) / 10)))
				return 0;
			res = res * 10 + tmp;
			x /= 10;
		}
		return res;
	}
	
	
	// update 2019.9.18
	int reverse2(int x) 
	{
		int res = 0;
		bool positive = (x >= 0) ? true : false;
		while (x != 0)
		{
			if (positive && (res > INT_MAX / 10 || res * 10 > INT_MAX - x % 10))
				return 0;
			if (!positive && (res < INT_MIN / 10 || res * 10 < INT_MIN - x % 10))
				return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
};

int main() 
{
	Solution a;
	cout << a.reverse(INT_MAX) << endl;



	


	system("pause");
	return 0;
}
