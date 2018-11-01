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

/*
这题很明显是用递归来做，但我就是不会写。
以第k个节点为根的所有二叉树，其左子树是[1,k-1]的所有二叉树组成，右子树是[k+1,n]的所有二叉树组成。
所以需要建立两个vector<TreeNode *>的表来存储左子树和右子树。
然后将这两个表两两组合。

https://blog.csdn.net/magicbean2/article/details/70254731
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) 
	{
		vector<TreeNode *> res;
		if (n < 1)
			return res;
		dfs(1, n, res);
		return res;
	}

	void dfs(int start, int end, vector<TreeNode *> &tree)
	{
		if (start > end)
		{
			tree.push_back(nullptr);
			return;
		}
		for (int i = start; i <= end; ++i)
		{
			vector<TreeNode *> left;
			vector<TreeNode *> right;
			dfs(start, i - 1, left);
			dfs(i + 1, end, right);
			for (int m = 0; m < left.size(); ++m)
			{
				for (int n = 0; n < right.size(); ++n)
				{
					TreeNode *root = new TreeNode(i);
					root->left = left[m];
					root->right = right[n];
					tree.push_back(root);
				}
			}
		}
	}
};




int main() 
{
	Solution a;
	vector<TreeNode*> b = a.generateTrees(3);






	system("pause");
	return 0;
}



