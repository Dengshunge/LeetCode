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
两种方法
第一种，二分法，将mid的平方与x比较，然后修改low和high的值，逐步逼近；
第二种，牛顿法，f(x)=i^2-x=0，求f(x)=0的根，所以x_k+1 = x_k - f(x_k)/f`(x_k)
*/

class Solution {
public:
	int mySqrt(int x) 
	{
		int low = 0, high = x;
		while (low <= high)
		{
			long mid = (low + high) >> 1;
			long temp = mid*mid;
			if (temp == x)
				return mid;
			else if (temp < x)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return high;
	}

	int mySqrt2(int x)
	{
		double i_last = 0;
		double i_new = 2;
		while (abs(i_new - i_last) >0.1)
		{
			i_last = i_new;
			i_new = (i_new + x / i_new) / 2;
		}
		return int(i_new);
	}
	
	//
	int mySqrt(int x)
	{
		long long left = 0, right = x;
		while (left < right)
		{
			long long mid = (left + right + 1) >> 1;
			if (mid*mid > x)
				right = mid - 1;
			else
				left = mid;
		}
		return left;
	}
};

int main() 
{
	Solution a;
	cout << a.mySqrt2(INT_MAX) << endl;



	system("pause");
	return 0;
}



