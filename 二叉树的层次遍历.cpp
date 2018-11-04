#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		if (!root)
			return {};
		vector<vector<int>> res;
		int curNode = 1, nextNode = 0;
		queue<TreeNode *> queue;
		queue.push(root);
		while (!queue.empty())
		{
			vector<int> path;
			while (curNode--)
			{
				TreeNode *p = queue.front();
				queue.pop();
				path.push_back(p->val);
				if (p->left)
				{
					queue.push(p->left);
					++nextNode;
				}
				if (p->right)
				{
					queue.push(p->right);
					++nextNode;
				}
			}
			res.push_back(path);
			curNode = nextNode;
			nextNode = 0;
		}
		return res;
	}
};


int main()
{
	TreeNode node1(3);
	TreeNode node2(9);
	TreeNode node3(20);
	TreeNode node4(15);
	TreeNode node5(7);

	//node1.left = &node2;
	//node1.right = &node3;
	//node3.left = &node4;
	//node3.right = &node5;


	Solution a;
	auto b = a.levelOrder(&node1);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}




	
	system("pause");
}

