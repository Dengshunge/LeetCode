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
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if (nums.empty())
			return nullptr;
		return sortedArrayToBST(nums, 0, nums.size() - 1);
	}

	TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end)
	{
		if (start > end)
			return nullptr;
		int mid = (start + end) >> 1;
		TreeNode *head = new TreeNode(nums[mid]);
		head->left = sortedArrayToBST(nums, start, mid - 1);
		head->right = sortedArrayToBST(nums, mid + 1, end);
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
	vector<int> nums{ -10,-3,0,5,9 };
	Solution a;
	TreeNode *b = a.sortedArrayToBST(nums);
	TreeNodePrint(b);


	system("pause");
	return 0;
}
