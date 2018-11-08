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
和上一题数组的一样，难点在于，链表如何选到中间节点，需要设置一个快慢指针。
其实判断条件是while(fast->next && fast->next->next)即可，无需一开始就初始化快慢指针。
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head)
	{
		if (!head)
			return nullptr;
		return sortedListToBST(head, nullptr);
	}

	TreeNode* sortedListToBST(ListNode* head, ListNode *end)
	{
		if (!head || head == end)
			return nullptr;
		ListNode *p1 = head->next;
		ListNode *p2;
		if (p1 && p1 != end)
			p2 = p1->next;
		else
			return new TreeNode(head->val);
		while (p2 != end && p2->next !=end && p2->next->next != end)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
		TreeNode *phead = new TreeNode(p1->val);
		phead->left = sortedListToBST(head, p1);
		phead->right = sortedListToBST(p1->next, end);
		return phead;
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
	ListNode node1(0);
	ListNode node2(1);
	ListNode node3(2);
	ListNode node4(3);
	ListNode node5(4);
	ListNode node6(5);
	ListNode node7(6);


	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;

	Solution a;
	TreeNode *b = a.sortedListToBST(&node1);
	TreeNodePrint(b);


	system("pause");
	return 0;
}
