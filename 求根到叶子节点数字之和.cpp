#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
要有两个判断条件，root为空和root->left&&root->right为空。

本题考的简单了，应该还要考虑大数问题的。
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	int sumNumbers(TreeNode* root)
	{
		if (!root)
			return 0;
		int res = 0;
		int path = 0;
		sumNumbers(root, res, path);
		return res;
	}

	void sumNumbers(TreeNode* root, int &res, int &path)
	{
		if (!root)
			return;
		if (!root->left && !root->right)
		{
			res += path * 10 + root->val;
			return;
		}
		path = path * 10 + root->val;
		sumNumbers(root->left, res, path);
		sumNumbers(root->right, res, path);
		path /= 10;
	}
};


int main() 
{
	TreeNode node1(4);
	TreeNode node2(9);
	TreeNode node3(0);
	TreeNode node4(5);
	TreeNode node5(1);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;

	Solution a;
	cout << a.sumNumbers(&node1) << endl;


	system("pause");
	return 0;
}
