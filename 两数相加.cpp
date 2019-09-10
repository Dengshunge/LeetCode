#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
		ListNode *head = new ListNode(-1);
		ListNode *p = head;
		while (l1||l2||carry)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
			p->next = new ListNode(sum % 10);
			carry = sum / 10;
			p = p->next;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		return head->next;
	}
};


int main()
{
	Solution a;

	ListNode node1(2);
	ListNode node2(4);
	ListNode node3(3);
	node1.next = &node2;
	node2.next = &node3;

	ListNode node4(5);
	ListNode node5(6);
	ListNode node6(4);
	node4.next = &node5;
	node5.next = &node6;

	auto p = a.addTwoNumbers(&node1, &node4);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;


	system("pause");
}

