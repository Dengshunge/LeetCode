'''
这是一题属于K-Sum类型，即K个数相加
首先要先对数组进行排序
我们可以先遍历所有值，然后在遍历的时候，设置两个指针，分别指向头和尾：
    1.当三数之和大于0，移动尾指针，让其值变小
    2.当三数之和小于0，移动头指针，让其值变大
    3.当三数之和等于0，插入list，并且要分别移动头尾指针，跳过重复的值
当然，在一开始遍历的时候，也需要跳过重复的值。
由于是排序过的，所以当遍历到正数的时候，后面就不必要再遍历了，可以结束了，因为三个正数不可能和为0

reference
1. https://blog.csdn.net/hujingshuang/article/details/51284090
2. https://blog.csdn.net/buptlrw/article/details/50545711
'''

class Solution:
    def threeSum(self,nums):
        if len(nums)<3:
            return []
        nums.sort()
        res = []
        length = len(nums)
        for i in range(length - 2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, length - 1
            while left < right:
                temp = nums[left] + nums[right] + nums[i]
                if temp == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] ==nums[left+1]:
                        left += 1
                    left += 1
                    while left < right and nums[right] == nums[right-1]:
                        right -= 1
                    right -1
                elif temp > 0:
                    right -= 1
                else:
                    left += 1
        return res

a = Solution()
print(a.threeSum([-1,0,1,2,-1,4]))
