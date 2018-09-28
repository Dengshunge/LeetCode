#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
	string HexAdd(const string num1, const string num2)
	{
		int i = num1.size() - 1, j = num2.size() - 1;
		bool carry = false;
		string Result = "OX";
		while (i > 1 && j > 1)
		{
			int Add = StringToNum(num1[i]) + StringToNum(num2[j]);
			//若上一轮有进位，则要在Add上加1
			if (carry)
			{
				Result += map[(Add + 1) % 16];
				carry = Add >= 16 ? true : false;
			}
			else
			{
				Result += map[Add % 16];
				carry = Add >= 16 ? true : false;
			}
			--i;
			--j;
		}
		//进行到这里，说明至少有一个数字已经循环完了
		while (i > 1)
		{
			int Add = StringToNum(num1[i]);
			if (carry)
			{
				Result += map[(Add + 1) % 16];
				carry = Add >= 16 ? true : false;
			}
			else
			{
				Result += map[Add % 16];
				carry = Add >= 16 ? true : false;
			}
			--i;
		}
		while (j > 1)
		{
			int Add = StringToNum(num2[j]);
			if (carry)
			{
				Result += map[(Add + 1) % 16];
				carry = Add >= 16 ? true : false;
			}
			else
			{
				Result += map[Add % 16];
				carry = Add >= 16 ? true : false;
			}
			--j;
		}
		if (carry)
			Result += '1';
		//由于上面得到的结果是反序的，所以这里需要将其翻转回来
		for (i = 2, j = Result.size() - 1; i < j; ++i, --j)
			swap(Result[i], Result[j]);
		return Result;
	}

	int StringToNum(const char s1)
	{
		int i = 0;
		for (; i < map.size(); ++i)
			if (map[i] == s1)
				break;
		return i;
	}

private:
	const vector<char> map{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
};


int main()
{
	Solution a;
	string s1 = "1FF";
	cout << a.HexAdd("OXAA", "OX1FF") << endl;
	
	system("pause");
}

