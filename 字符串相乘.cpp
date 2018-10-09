#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;


/*
这题是两数相乘，要考虑大数问题，所以一般使用字符串
第一种方法，就是传统的方法，num2每一位与num1相乘，然后相加。耗时比较大。
第二种方法，是leetcode上的方法，比较巧妙。
	先构造一个长度为num1.size()+num2.size()的vector，num1[i]*num2[j]放在vector的i+j和i+j+1位，前者为高位，后者为低位。
	并与原先该为的数字相加。
	方法比较巧妙，详情见https://blog.csdn.net/qq_14821023/article/details/50822207
*/

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		string res = "0";
		if (num1 == "0" || num2 == "0")
			return res;
		for (int i = num2.size() - 1; i >= 0; --i)
		{
			string s1 = multiply_num1Tosigle(num1, num2[i] - '0');
			s1 += string(num2.size() - 1 - i, '0');
			res = num1Addnum2(res, s1);
		}
		return res;
	}

	// num1是一个数字，num2是一位数
	string multiply_num1Tosigle(string num1, int num2)
	{
		string res = "";
		int carry = 0;
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			int temp = (num1[i] - '0') * num2;
			//进位计算
			temp += carry;
			carry = temp / 10;
			//加入结果
			res = to_string(temp % 10) + res;
		}
		if (carry)
			res = to_string(carry) + res;
		return res;
	}

	string num1Addnum2(string num1, string num2)
	{
		string res = "";
		bool carry = false;
		int i = num1.size() - 1, j = num2.size() - 1;
		for (; i >= 0 && j >= 0; --i, --j)
		{
			int temp = (num1[i] - '0') + (num2[j] - '0');
			if (carry)
				++temp;
			carry = temp >= 10 ? true : false;
			res = to_string(temp % 10) + res;
		}
		while (i >= 0)
		{
			if (carry)
			{
				int temp = num1[i] - '0' + 1;
				carry = temp >= 10 ? true : false;
				res = to_string(temp % 10) + res;
			}
			else
				res = num1[i] + res;
			--i;
		}
		while (j >= 0)
		{
			if (carry)
			{
				int temp = num2[j] - '0' + 1;
				carry = temp >= 10 ? true : false;
				res = to_string(temp % 10) + res;
			}
			else
				res = num2[j] + res;
			--j;
		}
		if (carry)
			res = "1" + res;
		return res;
	}
};


class Solution2
{
public:
	string multiply(string num1, string num2)
	{
		int m = num1.size(), n = num2.size();
		vector<int> arr(m + n);
		string res = "";
		for (int i = m - 1; i >= 0; --i)
		{
			for (int j = n - 1; j >= 0; --j)
			{
				int index1 = i + j;//表示高位
				int index2 = index1 + 1;//表示低位
				int sum = (num1[i] - '0')*(num2[j] - '0') + arr[index2];
				arr[index1] += sum / 10;//此时结果可能大于10，但不怕，最后会调整成单位
				arr[index2] = sum % 10;
			}
		}
		for (auto i : arr)
		{
			//当res非空或者i!=0时，加入字符串
			//当res为空，且第一位为0时，不加入字符串
			if (res.size() != 0 || i != 0)
				res += to_string(i);
		}
		return res.size() == 0 ? "0" : res;
	}
};

int main()
{
	string num1 = "123", num2 = "11";
	Solution a;
	cout << a.multiply(num1, num2) << endl;
	cout << stoi(num1) * stoi(num2) << endl;


	system("pause");
}

