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
与上题一样，只要设置一个标志位，反向插入即可
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		if (!root)
			return {};
		vector<vector<int>> res;
		queue<TreeNode *> que;
		que.push(root);
		bool flag = false;
		int curNode = 1, nextNode = 0;
		while (!que.empty())
		{
			vector<int> path;
			while (curNode--)
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
			if (flag)
				reverse(path.begin(),path.end());
			res.push_back(path);
			flag = !flag;
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

	node1.left = &node2;
	node1.right = &node3;
	node3.left = &node4;
	node3.right = &node5;


	Solution a;
	auto b = a.zigzagLevelOrder(&node1);
	for (auto m : b)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
