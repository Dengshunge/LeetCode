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
上一题是数字重复两次，而本题是数字数字重复三次。
当重复两次的时候，两个相同的数字异或，其结果为0；
本题的思路很特别，int类型是32位，将每个数字进行相加，一般情况下，某一位应该是能被3整除。
当其中一位不能被3整除，说明值出现1次的数字在该位有值。
https://blog.csdn.net/qq_36946274/article/details/81100699
https://blog.csdn.net/zsjwish/article/details/80038434

根据此思路，还可以创建一个32位的数组，将每个数组的二进制都统计起来。
*/


class Solution {
public:
	int singleNumber(vector<int>& nums) 
	{
		int sum = 0;
		int res = 0;
		for (int i = 0; i < 32; ++i)
		{
			for (int num : nums)
			{
				int tmp = (num >> i) & 1;
				sum += tmp;
			}
			if (sum % 3 != 0)
			{
				res |= 1 << i;
			}
			sum = 0;
		}
		return res;
	}
};


int main() 
{
	vector<int> nums{ 0,1,0,1,0,1,99 };
	Solution a;
	cout << a.singleNumber(nums) << endl;


	system("pause");
	return 0;
}
