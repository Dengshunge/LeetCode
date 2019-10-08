#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
使用了回溯法，一开始也想到了，但不知道怎么写。
思路是这样的，一开始往里面放左括号"("，直到左括号的数量为N，然后开始放右括号。
当右括号也放满了，就压入vector。
然后进行回溯，回溯到N-1个左括号的情况，然后压入右括号，进入新的迭代。

另外，官方给了另外一种思路来检验括号是否有效，可以与第20题比较。但这种情况是括号的类型是一致的。
思路是统计左括号的数量，遇到一个括号的时候，如果是左括号，数量加一，否则减一。
当数量小于0的时候，说明是无效的，到最后，如果数量不为0，也是说明无效的。
        def valid(A):
            bal = 0
            for c in A:
                if c == '(': 
			bal += 1
                else: 
			bal -= 1
                if bal < 0: 
			return False
            return bal == 0
*/

class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		N = n;
		backtrack();
		return res;
	}

	void backtrack(string s = "", int left = 0, int right = 0)
	{
		if (s.size() == 2 * N)
			res.push_back(s);
		if (left < N)
			backtrack(s + "(", left + 1, right);
		if (right < left)
			backtrack(s + ")", left, right + 1);
	}
private:
	int N = 0;
	vector<string> res;
};

//update 2019.10.8
class Solution {
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> res;
		generateParenthesis(n, 0, 0, "", res);
		return res;
	}
	void generateParenthesis(int n, int left,int right, string s, vector<string> &res)
	{
		if (right > left)
			return;
		if (n == left)
		{
			int tmp = left - right;
			s += string(tmp, ')');
			res.push_back(s);
			return;
		}
		generateParenthesis(n, left + 1, right, s + '(', res);
		generateParenthesis(n, left, right + 1, s + ')', res);
	}
};


int main()
{
	Solution a;
	auto b = a.generateParenthesis(1);
	for (auto item : b)
		cout << item << endl;



	system("pause");

}

