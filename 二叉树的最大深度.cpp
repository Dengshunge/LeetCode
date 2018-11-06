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
	int maxDepth(TreeNode* root) 
	{
		if (!root)
			return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
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
	cout << a.maxDepth(&node1) << endl;

	system("pause");
	return 0;
}
