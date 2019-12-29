#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>
#include "linearlist.cpp"

using namespace std;

class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) 
	{
		ListNode *p1 = headA, *p2 = headB;
		while (p1||p2)
		{
			if (p1 == p2)
				return p1;
			p1 = (p1 != nullptr) ? p1->next : headB;
			p2 = (p2 != nullptr) ? p2->next : headA;
		}
		return nullptr;
	}
};
