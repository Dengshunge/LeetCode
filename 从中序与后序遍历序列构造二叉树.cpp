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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		if (inorder.empty() || postorder.empty())
			return nullptr;
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& inorder, int istart, int iend,
		vector<int>& postorder, int pstart, int pend)
	{
		if (istart > iend || pstart > pend)
			return nullptr;
		TreeNode *head = new TreeNode(postorder[pend]);
		if (istart == iend)
			return head;
		int index = iend;
		for (; index >= istart; --index)
			if (inorder[index] == postorder[pend])
				break;
		int length = iend - index;
		head->left = buildTree(inorder, istart, iend - length - 1, postorder, pstart, pend - length - 1);
		head->right = buildTree(inorder, iend - length + 1, iend, postorder, pend - length, pend - 1);
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

	vector<int> inorder{ 9,3,15,20,7 };
	vector<int> postorder{ 9,15,7,20,3 };

	Solution a;
	TreeNode *p = a.buildTree(inorder, postorder);

	TreeNodePrint(p);


	system("pause");
	return 0;
}
