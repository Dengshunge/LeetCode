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

/*
方法有点复杂了，主要思路是递归寻找不重复的节点
写这么复杂是因为头结点处理困难，所以网上有种办法是设置一个新的头结点来处理，遇到重复的节点就删除。
https://blog.csdn.net/u012501459/article/details/46415249
*/

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
			return nullptr;
		head = deleteDuplicates_Core(head);
		ListNode *p = head;
		while (p)
		{
			p->next = deleteDuplicates_Core(p->next);
			p = p->next;
		}
		return head;
	}

	ListNode* deleteDuplicates_Core(ListNode* head)
	{
		if (!head)
			return nullptr;
		ListNode *p = head;
		while (p)
		{
			ListNode *p_next = p->next;
			if (!p_next || (p_next&&p_next->val != p->val))
				break;
			while (p_next&&p_next->val == p->val)
			{
				p_next = p_next->next;
			}
			p = p_next;
		}
		return p;
	}
};


int main() 
{
	Solution a;
	ListNode node1(1);
	ListNode node2(1);
	ListNode node3(2);
	ListNode node4(4);
	ListNode node5(4);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

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



