#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>
#include "linearlist.cpp"

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		bool flag = (dividend > 0) ^ (divisor > 0) ? true : false;//判断正负
		//转换为负数，防止越界
		dividend = (dividend > 0) ? -dividend : dividend;
		divisor = (divisor > 0) ? -divisor : divisor;
		int res = 0;//表示输出结果

		while (dividend <= divisor)
		{
			int temp_divisor = divisor, temp_result = -1;//temp_divisor表示除数，temp_result表示移动位数
			while (dividend <= (temp_divisor << 1))
			{
				if (temp_divisor <= (INT_MIN >> 1))
					break;//防越界
				temp_result <<= 1;
				temp_divisor <<= 1;
			}
			dividend -= temp_divisor;
			res += temp_result;
		}
		if (!flag)//负数
		{
			if (res <= INT_MIN)
				return INT_MAX;
			res = -res;
		}
		return res;
	}
};


int main()
{
	Solution a;
	
	cout << a.divide(10,3) << endl;


	system("pause");
}

