#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

/*
注意，这里是判断根节点到叶节点是否存在路径，所以可以用递归
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) 
	{
		if (!root)
			return false;
		if (root->val == sum && !root->left && !root->right)
			return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};


int main()
{
	TreeNode node1(5);
	TreeNode node2(4);
	TreeNode node3(8);
	TreeNode node4(11);
	TreeNode node5(13);
	TreeNode node6(4);
	TreeNode node7(7);
	TreeNode node8(2);
	TreeNode node9(1);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node3.left = &node5;
	node3.right = &node6;
	node4.left = &node7;
	node4.right = &node8;
	node6.right = &node9;


	Solution a;
	cout << boolalpha << a.hasPathSum(&node1, 5) << endl;




	
	system("pause");
}

