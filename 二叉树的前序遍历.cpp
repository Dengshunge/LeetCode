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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode *> nodeStack;
		TreeNode *p = root;
		while (p || !nodeStack.empty())
		{
			while (p)
			{
				result.push_back(p->val);
				nodeStack.push(p);
				p = p->left;
			}
			p = nodeStack.top();
			nodeStack.pop();
			p = p->right;
		}
		return result;
	}
};


int main() 
{
	TreeNode node1{ 1 };
	TreeNode node2{ 2 };
	TreeNode node3{ 3 };
	TreeNode node4{ 4 };




	


	system("pause");
	return 0;
}
