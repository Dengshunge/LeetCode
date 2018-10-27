#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

/*
思路不太难，但很讲究基本功
首先找到值比x大的前一个节点，作为插入的节点
然后找到所有值比x小的节点，更改next指向。
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * partition(ListNode* head, int x) 
	{
		if (!head)
			return nullptr;
		ListNode fakeHead(0);
		fakeHead.next = head;
		ListNode *p_insert = &fakeHead;
		//找到第一个大于等于x的节点的前一个节点，作为以后要插入的节点
		while (p_insert->next && p_insert->next->val < x)
			p_insert = p_insert->next;
		ListNode *p = p_insert->next;
		//接下来是插入操作
		while (p&&p->next)
		{
			//跳过值比x大的节点
			while (p->next && p->next->val >= x)
				p = p->next;
			if (!p->next)
				break;
			//更改节点的next
			ListNode *temp = p->next;
			p->next = temp->next;
			temp->next = p_insert->next;
			p_insert->next = temp;
			p_insert = p_insert->next;
		}
		return fakeHead.next;
	}
};


int main()
{
	ListNode node1(3);
	ListNode node2(3);
	ListNode node3(1);
	ListNode node4(2);
	ListNode node5(5);
	ListNode node6(2);

	node1.next = &node2;
	//node2.next = &node3;
	//node3.next = &node4;
	//node4.next = &node5;
	//node5.next = &node6;

	Solution a;
	ListNode *p = a.partition(&node1, 4);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	
	system("pause");
}
