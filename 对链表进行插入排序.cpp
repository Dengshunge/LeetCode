#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* insertionSortList(ListNode* head) 
	{
		if (!head)
			return nullptr;
		ListNode *headNode = new ListNode(0);
		headNode->next = head;
		ListNode *p = head;
		while (p->next)
		{
			if (p->val <= p->next->val)
			{
				p = p->next;
			}
			else
			{
				ListNode *tmp = p->next;
				p->next = p->next->next;
				for (ListNode *q = headNode; q != p; q = q->next)
				{
					if (q->next->val >= tmp->val)
					{
						tmp->next = q->next;
						q->next = tmp;
						break;
					}
				}
			}
		}
		return headNode->next;
	}
};


int main() 
{
	ListNode node1{ 4 };
	ListNode node2{ 2 };
	ListNode node3{ 1 };
	ListNode node4{ 3 };

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;

	Solution a;
	ListNode *p = a.insertionSortList(&node1);

	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;


	


	system("pause");
	return 0;
}
