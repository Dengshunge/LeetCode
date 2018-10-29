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
这里使用了两种方法
第一种，将中间的指针存起来，然后反向改写。注意，这里是存指针，而不是节点。如果存的节点，类似于复制重建了一个新的节点，改写不会改变原内容。
	这是第一次使用vector存储指针，运用不是很熟练。这里不能使用pop_back，原因不知道， 貌似是类型转换的问题。
第二种，利用三个指针，p_start永远指向m之前的一个结点。
*/


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		if (head == nullptr)
			return nullptr;
		ListNode fakeHead(0);
		fakeHead.next = head;
		ListNode *p1 = &fakeHead;
		while (--m&&--n)
			p1 = p1->next;
		vector<ListNode *> temp;
		ListNode *p2 = p1->next;
		while (n--)
		{
			temp.push_back(p2);
			p2 = p2->next;
		}
		for (int i = temp.size() - 1; i >= 0; --i)
		{
			ListNode *p = temp[i];
			p1->next = p;
			p1 = p1->next;
		}
		p1->next = p2;
		return fakeHead.next;
	}

	ListNode* reverseBetween2(ListNode* head, int m, int n)
	{
		if (head == nullptr)
			return nullptr;
		ListNode fakeHead(0);
		fakeHead.next = head;
		n = n - m;
		ListNode *p_start = &fakeHead;
		while (--m)
			p_start = p_start->next;
		ListNode *p_cur = p_start->next;
		while (n--)
		{
			ListNode *p_next = p_cur->next;
			p_cur->next = p_next->next;
			p_next->next = p_start->next;
			p_start->next = p_next;
		}
		return fakeHead.next;
	}
};



int main() 
{
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	Solution a;
	ListNode* p = a.reverseBetween2(&node1, 2, 4);
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;




	system("pause");
	return 0;
}



