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


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution 
{
public:
	ListNode *detectCycle(ListNode *head) 
	{
		if (!head)
			return nullptr;
		ListNode *slow = head;
		ListNode *fast = head;
		do
		{
			if (!fast || !fast->next || !fast->next->next)
				return nullptr;
			slow = slow->next;
			fast = fast->next->next;
		} while (slow != fast);
		
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};


int main() 
{
	ListNode node1{ 3 };
	ListNode node2{ 2 };
	ListNode node3{ 0 };
	ListNode node4{ -4 };

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node2;

	Solution a;
	ListNode *p = a.detectCycle(&node1);
	cout << p->val << endl;
	


	system("pause");
	return 0;
}
