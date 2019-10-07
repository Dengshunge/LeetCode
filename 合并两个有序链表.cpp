#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == nullptr & l2 == nullptr)
			return nullptr;
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		auto *p1 = l1, *p2 = l2;
		auto *res = new ListNode{ 0 };
		auto *k = res;
		while (p1 != nullptr & p2 != nullptr)
		{
			if (p1->val > p2->val)
			{
				k->next = new ListNode{ p2->val };
				p2 = p2->next;
			}
			else
			{
				k->next = new ListNode{ p1->val };
				p1 = p1->next;
			}
			k = k->next;
		}
		if (p1 == nullptr)
			k->next = p2;
		else
			k->next = p1;
		return res->next;
	}
	
	//2019.10.7
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		while (l1&&l2)
		{
			if (l1->val <= l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;
		return head->next;
	}
};

int main()
{
	ListNode node1{ 1 };
	ListNode node2{ 2 };
	ListNode node3{ 4 };
	ListNode node4{ 1 };
	ListNode node5{ 3 };
	ListNode node6{ 4 };
	node1.next = &node2;
	node2.next = &node3;

	node4.next = &node5;
	node5.next = &node6;


	Solution a;
	auto *p = a.mergeTwoLists(&node1, &node4);


	while (p != nullptr)
	{
		cout << p->val << endl;
		p = p->next;
	}

	system("pause");

}

