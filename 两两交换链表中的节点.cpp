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
  //update 2019.10.9
	ListNode * swapPairs(ListNode* head) 
	{
		if (!head || !head->next)
			return head;
		ListNode *phead = new ListNode(-1);
		ListNode *pPre = phead, *pCur = head;
		while (pCur&&pCur->next)
		{
			ListNode *pNext = pCur->next->next;
			pPre->next = pCur->next;
			pPre = pCur;
			pCur->next->next = pCur;
			pCur->next = pNext;
			pCur = pNext;
		}
		return phead->next;
	}
};


int main()
{
	Solution a;

	LinearList myList;
	ListNode *head = myList.ListCreat({ 1 });
	ListNode *p = a.swapPairs(head);
	myList.ListPrint(p);


	system("pause");
}

