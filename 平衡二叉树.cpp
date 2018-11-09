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
我以前的做法错了，以前认为只要检验根节点是否平衡就行，但忽略了这种情况
		1
	   / \
	  2   2
	 /     \
    3       3
   /         \
  4           4
所以，如果用这种方法，必须每个节点检查一次，会造成重复检查
应该使用剑指offer上的方法，后序遍历，将每个节点的深度保存起来
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isBalanced(TreeNode* root)
	{
		int depth = 0;
		return isBalanced(root, &depth);
	}
private:
	bool isBalanced(TreeNode* root, int *pDepth)
	{
		if (!root)
		{
			*pDepth = 0;
			return true;
		}
		int left = 0, right = 0;
		if (isBalanced(root->left, &left) && (isBalanced(root->right, &right)))
		{
			int dif = left - right;
			if (abs(dif) <= 1)
			{
				*pDepth = 1 + max(left, right);
				return true;
			}
		}
		return false;
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
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(3);
	TreeNode node6(4);
	TreeNode node7(4);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node4.left = &node6;
	node3.right = &node5;
	node5.right = &node7;

	Solution a;
	cout << boolalpha << a.isBalanced(&node1) << endl;


	system("pause");
	return 0;
}
