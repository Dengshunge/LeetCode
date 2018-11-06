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
本题的思路是，找到划分点，分成子前序和子中序，然后进入迭代。
虽然思路不难，但很考验对数组的操作。
*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		if (preorder.empty() || inorder.empty())
			return nullptr;
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}

	TreeNode *buildTree(vector<int>& preorder, int pleft, int pright,
		vector<int>& inorder, int ileft, int iright)
	{
		if (pleft > pright || ileft > iright)
			return nullptr;
		TreeNode *head = new TreeNode(preorder[pleft]);
		if (pleft == pright)
			return head;
		int i = ileft;
		for (; i <= iright; ++i)
		{
			if (inorder[i] == preorder[pleft])
				break;
		}
		int length = i - ileft;
		head->left = buildTree(preorder, pleft + 1, pleft + length, inorder, ileft, ileft + length - 1);
		head->right = buildTree(preorder, pleft + length + 1, pright, inorder, ileft + length + 1, iright);
		return head;
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
	//TreeNode node1(3);
	//TreeNode node2(9);
	//TreeNode node3(20);
	//TreeNode node4(15);
	//TreeNode node5(7);

	//node1.left = &node2;
	//node1.right = &node3;
	//node3.left = &node4;
	//node3.right = &node5;

	vector<int> preorder{ 1,2 };
	vector<int> inorder{ 2,1 };

	Solution a;
	TreeNode *p = a.buildTree(preorder, inorder);

	TreeNodePrint(p);


	system("pause");
	return 0;
}
