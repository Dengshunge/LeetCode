# 两数相加 Add Two Numbers
'''
这道题思路很简单，就是模拟加法的过程，有点类似于归并排序是的merge。
但写代码的时候可以简化些写法，例如使用p1+p2+carry，而不是先将p1+p2，再判断其进位和余数。
这样写会让思路更加清晰。
具体解答https://leetcode-cn.com/problems/add-two-numbers/solution/
另外，变式是说如果数字是按顺序存储在链表中，例如123：1-2-3，此时要如何相加呢？
我的想法是，类似于《剑指offer》的反转链表，可以利用辅助空间（两个栈）。
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1 or not l2:
            return None
        phead = ListNode(None)
        result = phead
        p1, p2 = l1, l2
        carry = 0
        while p1 and p2:
            temp = ListNode(p1.val + p2.val + carry)  # p1+p1+进位
            carry = temp.val // 10  # 表示进位
            temp.val %= 10  # 表示第一位
            result.next = temp
            result = temp
            p1,p2 = p1.next,p2.next
        # 到这一步，说明p1或者p2至少一个到头了，所以要补全后面
        while p1:
            temp = ListNode(p1.val + carry)
            carry = temp.val // 10
            temp.val %= 10
            result.next = temp
            result = temp
            p1 = p1.next
        while p2:
            temp = ListNode(p2.val + carry)
            carry = temp.val // 10
            temp.val %= 10
            result.next = temp
            result = temp
            p2 = p2.next
        if carry:
            result.next = ListNode(1)
        return phead.next

def creatListNode(nums):
    phead = ListNode(None)
    p = phead
    for i in nums:
        temp = ListNode(i)
        p.next = temp
        p = temp
    return phead.next

def Print(phead):
    while phead:
        print(phead.val,end=' ')
        phead = phead.next
    print()

nums1 = [2,4,3]
nums2 = [8,6,7]
node1 = creatListNode(nums1)
node2 = creatListNode(nums2)
Print(node1)
Print(node2)
a = Solution()
Print(a.addTwoNumbers(node1,node2))
