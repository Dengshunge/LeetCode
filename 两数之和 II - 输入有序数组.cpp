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
	vector<int> twoSum(vector<int>& numbers, int target) 
	{
		map<int, int> rest_index = {};
		for (int i = 0; i < numbers.size(); i++)
		{
			auto iter = rest_index.find(numbers[i]);
			if (iter != rest_index.end())
				return { iter->second + 1, i + 1 };
			else
				rest_index[target - numbers[i]] = i;
		}
		return {};
	}
};



int main()
{
	Solution a;
	
	vector<int> nums = { 2, 7, 11, 15 };
	auto b = a.twoSum(nums, 9);
	for (auto c : b)
		cout << c << " ";
	cout << endl;


	system("pause");
}

