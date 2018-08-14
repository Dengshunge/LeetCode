# 最长回文子串
'''
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000.
这道题可以使用中心扩展算法，也可以想到。
即找到一个中心，向两边扩展，当不是回文就退出，当是回文，则继续扩展。
'''

class Solution:
    def longestPalindrome(self,s1):
        start, end = 0, 0
        for i in range(len(s1)):
            len1 = self.expandAroundCenter(s1, i, i)
            len2 = self.expandAroundCenter(s1, i, i + 1)
            len_max = max(len1,len2)
            if len_max > end - start + 1:
                start = i - int((len_max - 1) / 2)
                end = i + int(len_max / 2)
        return s1[start:end+1]

    def expandAroundCenter(self,s1,left,right):
        while left >= 0 and right < len(s1) and s1[left] == s1[right]:
            left -= 1
            right += 1
        return right - left - 1

a = Solution()
print(a.longestPalindrome('abab'))
