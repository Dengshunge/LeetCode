#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
using namespace std;

/*
不断寻找子序列，当nCurSum<0时,当nums[i]>0时，此时新一轮的最大值是nums[i]，当nums[i]<0时，也没必要继续加，只会越加越小。

对于一个长度为n的数组A而言，从A[0] 到 A[j] 是一个子数组（j<n），
那么以A[j]结尾的子数组之最大和，要么是 A[j]， 要么是 max(A[i]~A[j-1])+A[j] ，其中0 ≤ i ≤ j-1。
*/
class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int nCurSum = nums[0];
		int nMaxSum = nums[0];
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nCurSum < 0)
				nCurSum = nums[i];
			else
				nCurSum += nums[i];
			if (nCurSum > nMaxSum)
				nMaxSum = nCurSum;
		}
		return nMaxSum;
	}
	
	//update 2019.11.10
	int maxSubArray2(vector<int>& nums) 
	{
		if (nums.empty())
			return 0;
		int maxadd = nums[0];
		int left = 0, right = 0;
		int cur = nums[0];
		while (right < nums.size() - 1)
		{
			if (cur <= 0)
			{
				right++;
				left = right;
				cur = nums[left];
			}
			else
			{
				right++;
				cur += nums[right];
			}
			if (cur > maxadd)
				maxadd = cur;
		}
		return maxadd;
	}
};



int main()
{
	vector<int> nums = { -2,0,-3 };
	Solution a;
	cout << a.maxSubArray(nums) << endl;




	system("pause");
}

