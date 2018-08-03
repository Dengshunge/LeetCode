# 两数之和
'''
这道题一开始看的时候，有点类似于《剑指offer》的面试题57：和为s的数字。
这那道题中，数组时排序数组，设置两个指针，分别指向头和尾。
当两者之和大于s时，把尾指针向前移；当两者之和小于s时，把头指针向后移。

但这题不是排序数组，是一个普通的序列。
这里有几种方法，leetcode都有详解。
    1. 暴力方法：把target-nums[i]与后面n-i项相比，看是否存在。此时复杂度为O(n^2)
    2. 利用哈希表，遍历两次。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
        然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]）是否存在于表中。
        注意，该目标元素不能是 nums[i]nums[i] 本身！此时时间复杂度为O(n)，空间复杂度为O(n)
    3. 利用哈希表，遍历一次。如果存在两数之和为target的话，数字是成对出现的，只是会有遍历的先后问题。所以我们可以一边
        把target - nums[i]存入哈希表，一边判断num[i]是否已经存在哈希表。此时间复杂度为O(n)，空间复杂度为O(n)。
'''

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return []
        hash_map = {}
        for i in range(len(nums)):
            if nums[i] in hash_map:
                return sorted([hash_map[nums[i]], i])
            hash_map[target - nums[i]] = hash_map.get(target - nums[i], i)
        return []

nums = [2,7,11,15]
target = 9
a = Solution()
print(a.twoSum(nums,target))
