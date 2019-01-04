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
很常见的题目，建议这里使用do...while，这样初始化的时候可以省略很多步骤
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution 
{
public:
	bool hasCycle(ListNode *head)
	{
		if (!head)
			return false;
		ListNode *slow = head;
		ListNode *fast = head;
		do
		{
			if (!fast || !fast->next || !fast->next->next)
				return false;
			slow = slow->next;
			fast = fast->next->next;
		} while (slow != fast);
		return true;
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
	cout << boolalpha << a.hasCycle(&node1) << endl;
	


	system("pause");
	return 0;
}
