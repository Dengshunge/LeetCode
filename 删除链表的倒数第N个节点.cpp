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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head == nullptr || n <= 0)
			return nullptr;
		ListNode* p1 = head;
		while (p1 && n>0)
		{
			p1 = p1->next;
			--n;
		}
		// 若链表长度小于n
		if (n != 0)
			return head;
		// 若删除的是头结点
		if (p1 == nullptr)
			return head->next;
		ListNode* p2 = head;
		while (p1->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		// p2指向的下一个节点是要删除的节点
		p2->next = p2->next->next;
		return head;
	}
	
	//2019.10.6
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode *pNext = head, *pCur = head;
		while (n--)
			pNext = pNext->next;
		if (!pNext)
			return head->next;
		while (pNext->next!=NULL)
		{
			pNext = pNext->next;
			pCur = pCur->next;
		}
		pCur->next = pCur->next->next;
		return head;
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
	auto *p = a.removeNthFromEnd(&node1, 5);

	//auto* p = &node1;
	while (p != nullptr)
	{
		cout << p->val << endl;
		p = p->next;
	}





	system("pause");

}

