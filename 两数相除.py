class Solution:
    # 暴力解法，dividend一直减去divisor，次数不断+1
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        signal = 1
        if dividend < 0:
            signal *= -1
            dividend *= -1
        if divisor < 0:
            signal *= -1
            divisor *= -1
        count = 0
        while dividend>=divisor:
            dividend -= divisor
            count += 1
        return signal * count

    # 进过优化的方法，相减的次数为1,2,4,8...
    # 例如10/3，第一次10-3，第二次10-6
    # 当然，如果想更加快，可以使用位运算
    def divide_1(self, dividend, divisor):
        if dividend == -pow(2,31) and divisor == -1:
            return pow(2, 31) - 1
        sign = 1
        if (dividend>0 and divisor<0) or (dividend<0 and divisor>0):
            sign = -1
        a, b = abs(dividend), abs(divisor)
        num = 0
        while a >= b:
            sum = b
            count = 1
            while (sum + sum) <= a:
                sum += sum
                count += count
            a = a - sum
            num = num + count
        return num if sign > 0 else -num


a = Solution()
print(a.divide_1(pow(2,30),3))
