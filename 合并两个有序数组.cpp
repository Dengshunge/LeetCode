#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	{
		int index = m + n - 1;
		int i = m - 1, j = n - 1;
		while (i >= 0 && j >= 0)
		{
			if (nums1[i] > nums2[j])
				nums1[index--] = nums1[i--];
			else
				nums1[index--] = nums2[j--];
		}
		while (j >= 0)
		{
			nums1[index--] = nums2[j--];
		}
	}
};


int main()
{
	vector<int>nums1{ 1,2,3,0,0,0 };
	vector<int>nums2{ 2,5,6 };
	Solution a;
	a.merge(nums1, 3, nums2, 3);
	for (auto i : nums1)
		cout << i << " ";
	cout << endl;


	
	system("pause");
}

