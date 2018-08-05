# 无重复字符的最长子串（Longest Substring Without Repeating Characters）
'''
这道题是《剑指offer》的面试题48
其思路是这样的，利用空间来换取效率，需要一个哈希表，只需要遍历一次字符串。
如果第i个字符没有出现过，则让curlength加一。
如果第i个字符出现过，设第i个字符和上一次出现过的距离为d：
    1.如果d>curlength，说明第i个字符不在当前子串中，可以curlength加一
    2.如果d<=curlength，说明第i个字符在当前子串中，此时让curlength=d
《剑指offer》上利用了动态规划的想法来讲解，和我的简易思路一致。

另外leetcode上有种“滑动窗口的解法”，其思路是，判断第i个字符是否在[j,i-1]的子串中，如果存在，则滑动窗口变成[i`+1,i];
如果不存在，则滑动窗口为[j,i]
'''
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        position = {}
        curlength,maxlength = 0,0
        for i in range(len(s)):
            if s[i] not in position:
                # 如果当前字母未出现过
                curlength += 1
            else:
                # 改字符出现过
                d = i - position[s[i]]
                if d >curlength:
                    # 如果上一次出现的位置大于当前子字符串长度，则不影响
                    curlength += 1
                else:
                    # 上一次出现的位置小于或等于当前子字符串长度
                    curlength = d
            position[s[i]] = i
            if curlength > maxlength:
                maxlength = curlength
        return maxlength

s = 'tmmzuxt'
a = Solution()
print(a.lengthOfLongestSubstring(s))
