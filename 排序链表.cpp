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

/*
https://www.cnblogs.com/tracyhan/p/5466158.html
https://www.cnblogs.com/ganganloveu/p/3763707.html

首先想到复杂度为O(nlogn)的排序算法有：快排，堆排和归并排序，三者的空间复杂度都为O(n)。
本例使用归并排序，归并排序如果用数组结构存储归并排序后的数据，则需要开辟出O(n)的空间来容纳数组，空间复杂度为O(n)，
但是若用链表作为数据结构，只需要改变next指针指向下一个归并后的顺序就行，空间复杂度降为O(1)。

*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* sortList(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		ListNode *mid = getMid(head);
		head = sortList(head);
		mid = sortList(mid);
		head = mergeList(head, mid);
		return head;
	}

private:
	//获得中间指针
	ListNode* getMid(ListNode* head)
	{
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *mid = slow->next;
		slow->next = nullptr;
		return mid;
	}

	//合并两个指针，形成有序
	ListNode* mergeList(ListNode* p1, ListNode* p2)
	{
		ListNode *newHead = new ListNode(0);
		ListNode *pre = newHead;
		while (p1&&p2)
		{
			if (p1->val <= p2->val)
			{
				pre->next = p1;
				p1 = p1->next;
			}
			else
			{
				pre->next = p2;
				p2 = p2->next;
			}
			pre = pre->next;
		}
		if (!p1)
			pre->next = p2;
		if (!p2)
			pre->next = p1;
		return newHead->next;
	}
};


int main() 
{
	ListNode node1{ 3 };
	ListNode node2{ 2 };
	ListNode node3{ 4 };
	ListNode node4{ 3 };

	node1.next = &node2;
	node2.next = &node3;
	//node3.next = &node4;

	Solution a;
	ListNode *p = a.sortList(&node1);

	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;



	


	system("pause");
	return 0;
}
