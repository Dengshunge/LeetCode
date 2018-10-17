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
旋转链表，思路不难，先遍历一次链表，记录节点数和将尾节点与头结点相连，组成一个环。
然后计算新的头结点的位置length - k % length
最后将节点断开即可。
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head == NULL || k == 0)
			return head;
		ListNode* p = head;
		int length = 1;
		while (p->next != NULL)
		{
			p = p->next;
			++length;
		}
		p->next = head;
		int n = length - k%length;
		p = head;
		while (n != 1)
		{
			p = p->next;
			--n;
		}
		ListNode* res_head = p->next;
		p->next = NULL;
		return res_head;
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
	
	ListNode *head = a.rotateRight(&node1,1);
	for (ListNode *p = head; p != NULL; p = p->next)
	{
		cout << p->val << " ";
	}
	cout << endl;



	system("pause");
	return 0;
}



