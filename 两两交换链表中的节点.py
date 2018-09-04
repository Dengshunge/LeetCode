
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        p1,p2 = head,head.next
        # 处理头2个节点
        p1.next = p2.next
        p2.next = p1
        head = p2

        p_pre = p1
        while p_pre.next:
            p1 = p_pre.next
            if p1.next:
                p2 = p1.next
            else:
                return head
            p1.next = p2.next
            p2.next = p1
            p_pre.next = p2
            p_pre = p1
        return head

    # 这是网上的方法，更加简洁
    # 思路一样，但其用了self，这个还不是特别懂
    def swapPairs_2(self, head):
        pre,pre.next = self,head
        while pre.next and pre.next.next:
            p1 = pre.next
            p2 = p1.next
            pre.next,p1.next,p2.next = p2,p2.next,p1
            pre = p1
        return self.next





node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node5 = ListNode(5)
node6 = ListNode(6)
node7 = ListNode(7)
node8 = ListNode(8)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node5
node5.next = node6
node6.next = node7
node7.next = node8

a = Solution()
b = a.swapPairs_2(node1)
while b:
    print(b.val,end=' ')
    b = b.next

