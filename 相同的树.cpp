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
	bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		if (!p && !q)
			return true;
		if (!p || !q)
			return false;
		if (p->val != q->val)
			return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};




int main() 
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(1);
	TreeNode node5(2);
	TreeNode node6(4);
	
	node1.left = &node2;
	node1.right = &node3;
	node4.left = &node5;
	node4.right = &node6;


	Solution a;
	cout << boolalpha << a.isSameTree(&node1, &node4) << endl;








	system("pause");
	return 0;
}
