# 字符串转整数
'''
对于Python，很容易去除前面的空格。
然后就是判断接下来的每一位是否符合标准
建议直接用int来处理，如果用string来处理，还需要进一步判断，挺麻烦的。
'''

class Solution:
    def myAtoi(self,s):
        INT_MAX,INT_MIN=pow(2,31)-1,-1*pow(2,31)
        s = s.strip()
        if not s:
            return 0
        flag = True
        i = 0
        if s[0]=='-' or s[0]=='+':
            if s[0]=='-':
                flag = False
            i+=1
        result = 0
        for c in range(i, len(s)):
            if s[c] < '0' or s[c] > '9':
                break
            digit = int(s[c])
            if flag:
                if (result < INT_MAX // 10) or (result == INT_MAX // 10 and digit <= 7):
                    result = result * 10 + digit
                else:
                    return INT_MAX
            else:
                #  注意 这里是地板除法
                if (result > (INT_MIN // 10 + 1)) or (result == (INT_MIN // 10 + 1) and digit <= 8):
                    result = result * 10 - digit
                else:
                    return INT_MIN
        return result


a = Solution()
print(a.myAtoi("-2147483647"))
