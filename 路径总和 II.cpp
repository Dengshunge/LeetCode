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
很久没写代码了，生疏了
很简单的思路，判断是否是叶子结点，并符合条件就插入
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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<int> path;
		if (root)
			pathSum(root, path, sum);
		return res;
	}

	//网上简洁版
	void pathSum(TreeNode* root, vector<int> &path, int sum)
	{
		if (!root)
			return;
		path.push_back(root->val);
		if (!root->left && !root->right && sum == root->val)
		{
			res.push_back(path);
			//注意，下面不能加return，否则会因为少弹出一次而出错。
			//return;
		}
		pathSum(root->left, path, sum - root->val);
		pathSum(root->right, path, sum - root->val);
		path.pop_back();
	}

	//自己的代码
	void pathSum2(TreeNode* root, vector<int> &path, int sum)
	{
		if (!root)
			return;
		int num = root->val;
		path.push_back(num);
		if (!root->left && !root->right)
		{
			if (sum == num)
			{
				res.push_back(path);
				return;
			}
			return;
		}
		if (root->left)
		{
			pathSum(root->left, path, sum - num);
			path.pop_back();
		}
		if (root->right)
		{
			pathSum(root->right, path, sum - num);
			path.pop_back();
		}
	}


private:
	vector<vector<int>> res;
};


int main() 
{
	TreeNode node1{ 5 };
	TreeNode node2{ 4 };
	TreeNode node3{ 8 };
	TreeNode node4{ 11 };
	TreeNode node5{ 13 };
	TreeNode node6{ 4 };
	TreeNode node7{ 7 };
	TreeNode node8{ 2 };
	TreeNode node9{ 5 };
	TreeNode node10{ 1 };

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node3.left = &node5;
	node3.right = &node6;
	node4.left = &node7;
	node4.right = &node8;
	node6.left = &node9;
	node6.right = &node10;

	Solution a;
	auto b = a.pathSum(&node1, 22);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
