#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x)
	{
		string s = to_string(x);
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			if (s[left] == s[right])
			{
				++left;
				--right;
			}
			else
				return false;
		}
		return true;
	}

	// 这是进阶版，不将整数转化为string
	// 将整数翻转一半来进行比较
	bool isPalindrome_1(int x)
	{
		// 负数或者最后一位为0，都是false
		if (x < 0 || (x != 0 && x % 10 == 0))
			return false;
		int revertedNumber = 0;
		// 当反转后的数字大于x时，说明已经反转了一半了
		while (revertedNumber < x)
		{
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}
		return x == revertedNumber || x == revertedNumber / 10;
	}
};


int main()
{
	Solution a;
	cout << a.isPalindrome_1(121) << endl;



	system("pause");

}

