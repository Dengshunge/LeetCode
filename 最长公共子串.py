# 求最长公共子串
'''
即abcde与abgde的最长公共子串的长度是2，可以是ab或者de
这题是典型的动态规划，令L[i,j]表示以s1[i]和s2[j]结尾的最长公共子串
当s1[i+1]=s2[j+1]时，说明下一个字符相同，公共子串的长度就加一，即L[i,j]=L[i-1,j-1]+1 
当s1[i+1]！=s2[j+1]时，L[i,j]=0
reference:
https://www.cnblogs.com/ider/p/longest-common-substring-problem-optimization.html
https://blog.csdn.net/zls986992484/article/details/69863710
'''
class Solution:
    def Longest_Public_Contiguous_Substring(self,s1,s2):
        if not s1 or not s2:
            return 0
        dp = [[0 for i in range(len(s2))] for i in range(len(s1))]
        # 处理第一行
        for j in range(len(s2)):
            if s1[0] == s2[j]:
                dp[0][j] = 1
        # 处理第一列
        for j in range(len(s1)):
            if s1[j] == s2[0]:
                dp[j][0] = 1

        # 处理剩下元素
        for i in range(1, len(s1)):
            for j in range(1, len(s2)):
                dp[i][j] = dp[i - 1][j - 1] + 1 if s1[i] == s2[j] else 0

        result=0
        for i in dp:
            temp = max(i)
            if temp > result:
                result = temp
        print(result)

a = Solution()
a.Longest_Public_Contiguous_Substring('abcde','abgda')
