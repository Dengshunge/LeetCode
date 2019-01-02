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

/*
https://www.cnblogs.com/jdneo/p/4748972.html
两种方法：
方法一，利用hash_map，把新旧节点的对应关系对应起来。首先遍历一次原链表，创建新的链表，处理好label和next，并把对应关系保存起来；
	第二次遍历的时候，处理random，通过hash_map来查询。时间和空间复杂度都是O(n)。
方法二，不使用hash_map，在原节点后面创建一个新的节点。重复三次遍历，第三次遍历是把链表拆分成两个。此时，时间复杂度是O(n)，空间复杂度是O(1)。

*/

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution 
{
public:
	RandomListNode *copyRandomList(RandomListNode *head) 
	{
		if (!head)
			return nullptr;
		map<RandomListNode*, RandomListNode*>oldToNew;	
		RandomListNode *newHead = new RandomListNode{ head->label };
		RandomListNode *p = head;
		RandomListNode *q = newHead;
		while (p->next)
		{
			oldToNew[p] = q;
			p = p->next;
			q->next = new RandomListNode{ p->label };
			q = q->next;
		}
		oldToNew[p] = q;

		p = head;
		q = newHead;
		while (p)
		{
			if (p->random)
			{
				q->random = oldToNew[p->random];
			}
			p = p->next;
			q = q->next;
		}
		return newHead;
	}
};


int main() 
{
	RandomListNode node1{ 1 };
	RandomListNode node2{ 2 };
	RandomListNode node3{ 3 };
	RandomListNode node4{ 4 };
	RandomListNode node5{ 5 };

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	node1.random = &node3;
	node2.random = &node1;
	node3.random = &node4;
	node4.random = &node1;

	Solution a;
	RandomListNode *p = a.copyRandomList(&node1);
	cout << p->label << endl;

	system("pause");
	return 0;
}
