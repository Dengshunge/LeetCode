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
这道题有两种方法：
方法一，利用vector来存储链表的每个节点指针，然后从两头开始，逐步修改。此时空间复杂度为O(n)。
方法二，首先找到链表的中点，将链表切开，分成链表1和链表2,。将链表2反转，最后将两个链表进行合并。此时空间复杂度为O(1).
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution 
{
public:
	void reorderList(ListNode* head) 
	{
		if (!head)
			return;
		vector<ListNode *> tmp;
		ListNode *p = head;
		while (p)
		{
			tmp.push_back(p);
			p = p->next;
		}
		int left = 0, right = tmp.size() - 1;
		for (; left < right; ++left, --right)
		{
			tmp[left]->next = tmp[right];
			tmp[right]->next = tmp[left + 1];
		}
		tmp[left]->next = nullptr;
	}

	void reorderList_network(ListNode* head)
	{
		if (!head)
			return;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast&&fast->next&&fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}//slow指针指向链表的中点
		//将后面的链表反转
		ListNode *cur = slow->next;
		slow->next = nullptr;
		ListNode *pre = nullptr;
		while (cur)
		{
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}//此时，pre指针指向最后一个结点
		//将两个链表进行合并
		ListNode *p1 = head, *p2 = pre;
		while (p1&&p2)
		{
			ListNode *tmp = p2->next;
			p2->next = p1->next;
			p1->next = p2;
			p1 = p1->next->next;
			p2 = tmp;
		}
	}
};


int main() 
{
	ListNode node1{ 1 };
	ListNode node2{ 2 };
	ListNode node3{ 3 };
	ListNode node4{ 4 };
	ListNode node5{ 5 };

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	Solution a;
	a.reorderList_network(&node1);
	ListNode *p = &node1;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	


	system("pause");
	return 0;
}
