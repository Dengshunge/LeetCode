'''
是个配对问题，我想到了四则表达式的后缀表达式
所以可以利用一个栈，遇到左括号，然如栈，遇到右括号，判断与栈顶元素是否是同一类型，如果是，弹出，如果不是，结束循环，输出false
'''

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True
        left_Parentheses = ['(','[','{']
        right_Parentheses = [')',']','}']
        lis = []
        for i in s:
            if i in left_Parentheses:
                lis.append(i)
            elif i in right_Parentheses:
                if lis:
                    index_left = left_Parentheses.index(lis[-1])
                else:
                    return False
                index_right = right_Parentheses.index(i)
                if index_left==index_right:
                    lis.pop(-1)
                else:
                    break
            else:
                # 出现其他字符
                return False
        if not lis:
            return True
        else:
            return False

s = ''
a = Solution()
print(a.isValid(s))
