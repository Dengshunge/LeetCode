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



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) 
	{
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode *> que;
		que.push(root);
		int cur = 1, nextNode = 0;
		while (!que.empty())
		{
			vector<int> path;
			while (cur--)
			{
				TreeNode *p = que.front();
				path.push_back(p->val);
				que.pop();
				if (p->left)
				{
					que.push(p->left);
					++nextNode;
				}
				if (p->right)
				{
					que.push(p->right);
					++nextNode;
				}
			}
			cur = nextNode;
			nextNode = 0;
			res.push_back(path);
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

void TreeNodePrint(TreeNode *head)
{
	if (head)
	{
		cout << head->val << endl;
		TreeNodePrint(head->left);
		TreeNodePrint(head->right);
	}
}

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
	auto b = a.levelOrderBottom(&node1);

	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
