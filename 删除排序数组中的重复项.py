'''
这题是数组的删除，而以前做的是链表的删除，有些区别
由于是数组，所以不能改变数组的长度，即不能删除元素。
所以我采用的办法是利用双指针，覆盖重复的元素.

而网上的方法更加简单，我的方法略微复杂了
'''

class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        p1,p2 = 0,0
        length = len(nums)
        count = 0
        while p1 < length:
            if p1 >0 and nums[p1] == nums[p1 - 1]:
                while p1 < length and nums[p1] == nums[p1 - 1]:
                    p1 += 1
            else:
                count += 1
                nums[p2] = nums[p1]
                p1 += 1
                p2 += 1
        return count

    def removeDuplicates_2(self, nums):
        if not nums:
            return 0
        i = 0
        length = len(nums)
        for j in range(1,length):
            if nums[j] != nums[i]:
                i += 1
                nums[i] = nums[j]
        return i+1

a = Solution()
lis = [0,0,1,1,1,2,2,3,3,4]
# lis = [1,2,3,4,5]
a.removeDuplicates_2(lis)
