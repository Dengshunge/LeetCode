#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;
		auto n = s.size();
		int cycleLen = 2 * numRows - 2;
		string result;
		for (int i = 0; i < numRows; ++i)
		{
			for (int j = 0; i + j < n; j += cycleLen)
			{
				result += s[i + j];
				if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
					result += s[j + cycleLen - i];
			}
		}
		return result;
	}
};


int main()
{
	Solution a;
	cout << a.convert("ABCDEFGHIJKLMN", 3) << endl;




	system("pause");

}

