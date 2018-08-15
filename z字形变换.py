#z字形变换
'''
规律很巧妙，这题只能多举几个例子，找规律。
难找的是中间的数字的规律。
'''
class Solution:
    def convert(self, s, numRows):
        if not s:
            return ''
        if numRows == 1:
            return s
        length = len(s)
        cycleLen = 2 * numRows - 2  # 一个循环的个数
        result = ''
        for i in range(numRows):# i代表行数
            j = 0  # j用于在不同周期内跳转
            # j都是在那几个值变化0,cycleLen,2cycleLen...
            # 可以理解为每次都是在一个周期的开头
            # 而用j+i来控制在每个周期的位置
            # cycleLen-i表示在一个周期内，中间的那几个数字。
            while i + j < length:
                result += s[j + i]
                if i != 0 and i != numRows - 1 and j + cycleLen - i < length:
                    result += s[j + cycleLen - i]
                j += cycleLen
        return result

a=Solution()
print(a.convert('ABCDEFGHIJKLMN',2))
