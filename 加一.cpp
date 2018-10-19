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
	vector<int> plusOne(vector<int>& digits) 
	{
		int carry = 1;
		for (int i = digits.size() - 1; carry==1 && i >= 0; --i)
		{
			int temp = digits[i] + carry;
			if (temp == 10)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i] = temp;
				carry = 0;
			}
		}
		if (carry)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main() 
{
	Solution a;
	vector<int> digits = { 9 };
	auto b = a.plusOne(digits);
	for (auto i : b)
		cout << i << " ";
	cout << endl;



	system("pause");
	return 0;
}



