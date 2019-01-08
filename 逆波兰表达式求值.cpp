#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
using namespace std;




class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> intSta;
		for (int i = 0; i < tokens.size(); ++i)
		{
			if (tokens[i] == "+")
			{
				int a = intSta.top();
				intSta.pop();
				int b = intSta.top();
				intSta.pop();
				intSta.push(b + a);
			}
			else if (tokens[i] == "-")
			{
				int a = intSta.top();
				intSta.pop();
				int b = intSta.top();
				intSta.pop();
				intSta.push(b - a);
			}
			else if (tokens[i] == "*")
			{
				int a = intSta.top();
				intSta.pop();
				int b = intSta.top();
				intSta.pop();
				intSta.push(b * a);
			}
			else if (tokens[i] == "/")
			{
				int a = intSta.top();
				intSta.pop();
				int b = intSta.top();
				intSta.pop();
				intSta.push(b / a);
			}
			else
			{
				intSta.push(stoi(tokens[i]));
			}
		}
		return intSta.top();
	}
};


int main() 
{
	vector<string> tokens{ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	Solution a;
	cout << a.evalRPN(tokens) << endl;



	


	system("pause");
	return 0;
}
