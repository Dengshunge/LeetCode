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
和上一题的区别是，这是普通的二叉树，中间会有空缺的节点；
题目要求常数的辅助空间，所以不能使用队列进行BFS
自己使用了类似上一题的方法，但写的比较复杂，需要设置3个指针，分别指向存在子节点的父节点、当前子节点，每层存在子节点的最左节点。
主要难点是如何判断next指针的情况，有几种情况：
1.当前结点是父节点的左节点：
	1.1父节点存在右节点，当前结点的next指向右节点
	1.2父节点不存在右节点，即将父节点指向父节点的next，然后判断是否子节点，并是当前结点指向这个。
2.当前结点是父节点的有节点，即判断下一个父节点的子树。
可以将两种情况合并一下，但总体来说，还是比较复杂

网上的方法比较简单，首先创建一个缓存结点，用来记录，再创建一个指针，指向这个缓存结点。
https://blog.csdn.net/qq_36627886/article/details/80359679
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

class Solution 
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)
			return;
		TreeLinkNode *parent = root;
		TreeLinkNode *current = nullptr;
		TreeLinkNode *first = root->left ? root->left : root->right;
		while (first)
		{
			current = first;
			while (current)
			{
				if (current == parent->left && parent->right)
					current->next = parent->right;
				else
				{
					current->next = FindNode(parent->next);
					parent = parent->next;
				}
				current = current->next;
			}
			parent = first;
			while (parent && !(parent->left || parent->right))
				parent = parent->next;
			if (!parent)
				return;
			first = parent->left ? parent->left : parent->right;
		}
	}

	void connect_network(TreeLinkNode *root)
	{
		TreeLinkNode *temp = new TreeLinkNode(0);//缓存结点
		TreeLinkNode *left = temp;
		while (root)
		{
			if (root->left)
			{
				left->next = root->next;
				left = root->left;
			}
			if (root->right)
			{
				//这里的left是已经指向同一层中前一个结点，所以要连接下一个右节点
				left->next = root->right;
				left = root->right;
			}
			root = root->next;//当前父节点已经遍历完，进入同一层中下一个父节点
			if (!root)
			{
				//若为空，说明同一层遍历完了，要开始将root变到下一层
				left = temp;
				root = temp->next;
				temp->next = nullptr;
			}
		}
	}

private:
	//用于寻找父节点下存在的左右节点，并返回子节点
	TreeLinkNode* FindNode(TreeLinkNode *root)
	{
		while (root)
		{
			if (root->left)
				return root->left;
			else if (root->right)
				return root->right;
			else
				root = root->next;
		}
		return nullptr;
	}
};



int main() 
{
	TreeLinkNode node1{ 1 };
	TreeLinkNode node2{ 2 };
	TreeLinkNode node3{ 3 };
	TreeLinkNode node4{ 4 };
	TreeLinkNode node5{ 5 };
	TreeLinkNode node6{ 6 };
	TreeLinkNode node7{ 7 };

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	//node2.right = &node5;
	node3.right = &node5;
	node4.left = &node6;
	node5.right = &node7;

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
	return 0;
}
