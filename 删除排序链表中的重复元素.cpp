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


struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) 
	{
		if (!head)
			return head;
		ListNode *p = head;
		while (p)
		{
			ListNode *p_next = p->next;
			while (p_next&&p_next->val == p->val)
				p_next = p_next->next;
			p->next = p_next;
			p = p->next;
		}
		return head;
	}
};


int main() 
{
	Solution a;
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(3);
	ListNode node5(3);

	//node1.next = &node2;
	//node2.next = &node3;
	//node3.next = &node4;
	//node4.next = &node5;

	ListNode *p = a.deleteDuplicates(&node1);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;



	system("pause");
	return 0;
}



