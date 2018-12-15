#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

/*
自己想到的方法，使用层次遍历的方法。
网上的方法，使用一个指针记录父节点，父节点是已经处理好的，接下来是处理当前节点
	详情见注释，方法很巧妙，类似于分治法。
*/

//struct TreeNode {
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)
			return;
		queue<TreeLinkNode *> que;
		que.push(root);
		int curNode = 1;
		int nextNode = 0;
		while (!que.empty())
		{
			while (curNode)
			{
				TreeLinkNode *curTree = que.front();
				que.pop();
				--curNode;
				if (curTree->left)
				{
					que.push(curTree->left);
					++nextNode;
				}
				if (curTree->right)
				{
					que.push(curTree->right);
					++nextNode;
				}
				if (curNode)
					curTree->next = que.front();
				else
					curTree->next = nullptr;
			}
			curNode = nextNode;
			nextNode = 0;
		}
	}

	void connect_network(TreeLinkNode *root)
	{
		if (!root)
			return;
		root->next = nullptr;
		TreeLinkNode *parent = root;
		TreeLinkNode *current = nullptr;
		TreeLinkNode *left = root->left;//指向每层的最左边的节点
		while (left)
		{
			//因为是完全二叉树，所以肯定存在最后一层的做节点
			current = left;
			while (current)
			{
				//循环当层的所有节点
				if (current == parent->left)
					//如果是父节点的左节点，只需要把current节点连接到父节点的右子树上
					current->next = parent->right;
				if (current == parent->right)
				{
					//如果是父节点的右节点，则有两种情况
					//1.父节点的next存在，则将current连接到父节点的next的左节点上，并且调整父节点
					//2.父节点的next不存在，则将current连接Null，并且说明已经到尽头了，把left调整到下一层的开始
					if (parent->next)
					{
						parent = parent->next;
						current->next = parent->left;
					}
					else
					{
						current->next = nullptr;
						parent = left;
						left = left->left;
					}
				}
				current = current->next;
			}
		}
	}
};


int main()
{
	TreeLinkNode node1(1);
	TreeLinkNode node2(2);
	TreeLinkNode node3(3);
	TreeLinkNode node4(4);
	TreeLinkNode node5(5);
	TreeLinkNode node6(6);
	TreeLinkNode node7(7);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.left = &node7;

	Solution a;
	a.connect(&node1);

	TreeLinkNode *p = &node1;
	while (p)
	{
		TreeLinkNode *q = p;
		while (q)
		{
			cout << q->val << " ";
			q = q->next;
		}
		cout << endl;
		p = p->left;
	}

	
	system("pause");
}

