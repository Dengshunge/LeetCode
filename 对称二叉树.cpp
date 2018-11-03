#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
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
	bool isSymmetric(TreeNode* root) 
	{
		if (!root)
			return true;
		return isSymmetric(root->left, root->right);
	}
private:
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (!left && !right)
			return true;
		if (!left || !right)
			return false;
		if (left->val != right->val)
			return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};

int main() 
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(4);
	TreeNode node7(3);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;

	Solution a;
	cout << boolalpha << a.isSymmetric(&node1) << endl;

	system("pause");
	return 0;
}
