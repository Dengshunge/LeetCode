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
有几种方法，可以将每位转化为int运算，这样会简单很多。
另外可以使用位运算，但这里需要考虑多点条件，但也不算太复杂
*/

class Solution {
public:
	string addBinary(string a, string b) 
	{
		int aLength = a.size(), bLength = b.size();
		int length = aLength;
		//在短的字符前插入0
		if (aLength > bLength)
		{
			length = aLength;
			b.insert(b.begin(), aLength - bLength, '0');
		}
		else if (aLength < bLength)
		{
			length = bLength;
			a.insert(a.begin(), bLength - aLength, '0');
		}

		int carry = 0;
		string res = "";
		for (int i = length - 1; i >= 0; --i)
		{
			int temp = (a[i] - '0') ^ (b[i] - '0') ^ carry;
			if (carry)
				carry = ((a[i] - '0') | (b[i] - '0')) & carry;
			else
				carry = (a[i] - '0') & (b[i] - '0');
			res = to_string(temp) + res;
		}
		if (carry)
			res = "1" + res;
		return res;
	}
};

int main() 
{
	Solution a;
	cout << a.addBinary("0", "0") << endl;



	system("pause");
	return 0;
}



