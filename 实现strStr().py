'''
就是KMP算法
'''

class Solution:
    def strStr(self, haystack, needle):
        # hello
        # ll
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if not needle:
            return 0
        next_needle = self.get_next(needle)
        i,j = 0,0
        while i < len(haystack) and j < len(needle):
            if j==-1 or haystack[i] == needle[j]:
                # 当j=-1的时候，说明没匹配到字符串，该前移了，这段程序结束后的结果是，haystack[i]移动到下一个字符，而needle[j]从0开始
                # 重新比较
                i+=1
                j+=1
            else:
                j = next_needle[j]
        if j == len(needle):
            return i - j
        return -1

    def get_next(self,needle):
        length = len(needle)
        next_needle = [None] * (length+1)
        next_needle[0] = -1
        i,j = 0,-1
        while i < length:
            # neddle 为  abcdabd
            if j == -1 or needle[i] == needle[j]:
                i += 1
                j += 1
                next_needle[i] = j
            else:
                j = next_needle[j]
        return next_needle

a = Solution()
print(a.strStr('hello','la'))
