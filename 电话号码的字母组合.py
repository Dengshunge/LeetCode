'''
使用回溯法，难度不大。

'''

class Solution:
    def __init__(self):
        self.NumsToString = {'2': list('abc'), '3': list('def'), '4': list('ghi'), '5': list('jkl'), '6': list('mno'),
                        '7': list('pqrs'), '8': list('tuv'), '9': list('wxyz')}
        self.length = 0
        self.res = []

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        self.length = len(digits)
        for i in self.NumsToString[digits[0]]:
            self.letterCombinations_Core(digits[1:], i)
        return self.res

    def letterCombinations_Core(self,digits,s):
        if len(s) == self.length:
            self.res.append(s)
        else:
            for i in self.NumsToString[digits[0]]:
                s = s + i
                self.letterCombinations_Core(digits[1:], s)
                s = s[:-1]


a = Solution()
print(a.letterCombinations('2222'))
