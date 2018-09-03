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


int main()
{
	Solution a;
	auto b = a.generateParenthesis(1);
	for (auto item : b)
		cout << item << endl;



	system("pause");

}

