#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

/*
将二叉树转换成链表，即将右子树变成next；
所以，将左子树变成右子树，将右子树插入原来左子树的有节点处
            1                        1                   1
	   / \                        \                   \
	  2   6                        2                   2
	 /             ->             / \       ->          \
	3                            3   6                   3
       / \                          / \                     / \
      4   5                        4   5                   4   5
                                                                \
                                                                 6
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root)
	{
		if (root)
		{
			if (root->left)
			{
				TreeNode *p_right = root->right;
				root->right = root->left;
				root->left = nullptr;
				TreeNode *p = root->right;
				while (p->right)
				{
					p = p->right;
				}
				p->right = p_right;
			}
			flatten(root->right);
		}
	}
};


int main()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	//TreeNode node7(7);
	//TreeNode node8(2);
	//TreeNode node9(1);

	node1.left = &node2;
	node1.right = &node5;
	node2.left = &node3;
	node2.right = &node4;
	node5.right = &node6;


	Solution a;
	a.flatten(&node1);
	TreeNode *p = &node1;
	while (p)
	{
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;




	
	system("pause");
}

