# 翻转整数
'''
两种思路：
1. 将其转化为字符串操作，类似于第一种方法
2. 利用类似于栈的方法，将一位一位压入，再弹出
'''

class Solution:
    def reverse(self,num):
        if not num:
            return num
        arr = list(str(num))
        left, right = 0, len(arr) - 1
        if arr[0] == '-':
            left = 1
        while arr[right] == '0':
            right -= 1
        end = right
        while left < right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
            result = int(''.join(arr[:end + 1]))
        if result >= pow(2, 31) - 1 or result <= -pow(2, 31):
            return 0
        else:
            return result

    def reverse_1(self,num):
        INT_MAX = pow(2, 31) - 1
        INT_MIN = -1 * pow(2, 31)
        rev = 0
        while num != 0:
            pop = num % 10
            num //= 10
            if rev > INT_MAX / 10 or (rev == INT_MAX and pop > 7):
                return 0
            if rev < INT_MIN / 10 or (rev == INT_MAX and pop < -8):
                return 0
            rev = rev * 10 + pop
        return rev

a = Solution()
print(a.reverse_1(2))
