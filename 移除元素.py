'''
与上一题“删除排序数组中的重复项”一样，利用双指针

但官方给了另外一种思路，我们这种思路，当要删除的元素很少时，移动操作过多。
官方的想法是，将重复的元素方法后面，这样交换的次数就少了。
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
https://leetcode-cn.com/problems/remove-element/solution/

'''
class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if not nums:
            return 0
        i = 0
        count = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
                count += 1
        return count

nums = [0,1,2,2,3,0,4,2]
a = Solution()
b = a.removeElement(nums,2)
print(b)
print(nums[:b])
