#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	// 暴力解法
	int maxArea(vector<int>& height) 
	{
		if (height.size() < 2)
			return 0;
		int res = 0;
		for (int i = 0; i < height.size(); ++i)
		{
			for (int j = i + 1; j < height.size(); ++j)
			{
				int min_high = height[i] > height[j] ? height[j] : height[i];
				int len = j - i;
				int area = len*min_high;
				if (area > res)
				{
					res = area;
				}
			}
		}
		return res;
	}

	// 双指针法
	// 将两个指针分别指向头和尾，移动其中一个指针，记录最大面积
	// 将指向长度短的指针移向长度长的指针。
	// 因为最大面积受限于最短高度，当我们移动高度矮的指针后，面积才有可能增加
	// 若移动高度高的指针，由于两指针长度减小，所以无论移动后的指针指向的高度是否增加，最大面积都会减小。
	int maxArea_1(vector<int>& height)
	{
		if (height.size() < 2)
			return 0;
		auto left = height.cbegin(), right = height.cend() - 1;
		int area = 0;
		while (left < right)
		{
			int min_high = *left > *right ? *right : *left;
			int temp = (right - left)*min_high;
			if (temp > area)
				area = temp;
			if (*left < *right)
				++left;
			else
				--right;
		}
		return area;
	}
	
	//update 2019.3.1
	int maxArea(vector<int>& height) 
	{
		int val = 0;
		int left = 0, right = height.size() - 1;
		while (right>left)
		{
			int cur_val = (right - left)*min(height[left], height[right]);
			if (cur_val>val)
				val = cur_val;
			if (height[left]>height[right])
				--right;
			else
				++left;
		}
		return val;
	}
	
	//update 2019.9.24
	int maxArea2(vector<int>& height) 
	{
		int max_water = 0;
		int left = 0, right = height.size() - 1;
		while (left<right)
		{
			int length = right - left;
			int width = min(height[left], height[right]);
			max_water = (max_water > length*width) ? max_water : length * width;
			if (height[left] > height[right])
				--right;
			else
				++left;
		}
		return max_water;
	}
};


int main()
{
	Solution a;
	vector<int> vec{ 1,8,6,2,5,4,8,3,7 };
	cout << a.maxArea_1(vec) << endl;



	system("pause");

}

