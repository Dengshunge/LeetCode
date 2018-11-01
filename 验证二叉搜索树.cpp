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
方法一，利用中序遍历
方法二，当前结点的值大于左子树，小于右子树。但不能单纯比较左右节点的值，而是应该利用区间比较
	 10
	/  \
   5   15
       / \
      6   20
这种情况就是单纯比较左右节点的值。

https://www.cnblogs.com/ljdblog/p/6721418.html
https://blog.csdn.net/qq_17550379/article/details/82315830
*/


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
	bool isValidBST(TreeNode* root)
	{
		if (!root)
			return true;
		TreeNode *p = root;
		vector<TreeNode *> tree;
		vector<int> temp;
		while (p || !tree.empty())
		{
			while (p)
			{
				tree.push_back(p);
				p = p->left;
			}
			p = tree.back();
			tree.pop_back();
			if (temp.empty())
				temp.push_back(p->val);
			else
			{
				if (p->val <= temp[0])
					return false;
				else
					temp[0] = p->val;
			}
			p = p->right;
		}
		return true;
	}
};




int main() 
{
	TreeNode node1(3);
	TreeNode node2(1);
	TreeNode node3(4);
	TreeNode node4(3);
	TreeNode node5(6);
	
	node1.left = &node2;
	node1.right = &node3;
	//node3.left = &node4;
	//node3.right = &node5;


	Solution a;
	cout << boolalpha << a.isValidBST(&node1) << endl;








	system("pause");
	return 0;
}



