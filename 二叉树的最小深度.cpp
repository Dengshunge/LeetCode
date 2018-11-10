#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
/*
一种方法是递归
另外一种是BFS，当遇到叶子节点的两个子节点都是空，就返回
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) 
	{
		if (!root)
			return 0;
		if (!root->left)
			return minDepth(root->right) + 1;
		if (!root->right)
			return minDepth(root->left) + 1;
		return  min(minDepth(root->left), minDepth(root->right)) + 1;
	}

	int minDepth2(TreeNode* root)
	{
		if (!root)
			return 0;
		queue<TreeNode *> que;
		que.push(root);
		int cur = 1, nex = 0;
		int level = 1;
		while (!que.empty())
		{
			while (cur--)
			{
				TreeNode *p = que.front();
				que.pop();
				if (!p->left && !p->right)
					return level;
				if (p->left)
				{
					que.push(p->left);
					++nex;
				}
				if (p->right)
				{
					que.push(p->right);
					++nex;
				}
			}
			++level;
			cur = nex;
			nex = 0;
		}
		return level;
	}
};


int main()
{
	TreeNode node1(3);
	TreeNode node2(9);
	TreeNode node3(20);
	TreeNode node4(15);
	TreeNode node5(7);

	node1.left = &node2;
	node1.right = &node3;
	node3.left = &node4;
	node3.right = &node5;


	Solution a;
	cout << a.minDepth(&node1) << endl;




	
	system("pause");
}

