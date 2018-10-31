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
	vector<int> inorderTraversal(TreeNode* root) 
	{
		if (root == nullptr)
			return {};
		vector<int> res;
		vector<TreeNode *> temp;
		TreeNode *p = root;
		while (p || !temp.empty())
		{
			while (p)
			{
				temp.push_back(p);
				p = p->left;
			}
			p = temp.back();
			temp.pop_back();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
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
	TreeNode node7(7);
	TreeNode node8(8);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
	node3.left = &node6;
	node3.right = &node7;
	node4.left = &node8;

	Solution a;
	auto b = a.inorderTraversal(&node1);
	for (auto i : b)
		cout << i << " ";
	cout << endl;





	system("pause");
	return 0;
}



