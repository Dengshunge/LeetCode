# LeetCode
利用python和C++来刷题

## 两数之和
题目：[给定一个整数数组和一个目标值，找出数组中和为目标值的两个数](https://leetcode-cn.com/problems/two-sum/description/)  
解析：这道题一开始看的时候，有点类似于《剑指offer》的面试题57：和为s的数字。  
这那道题中，数组时排序数组，设置两个指针，分别指向头和尾。  
当两者之和大于s时，把尾指针向前移；当两者之和小于s时，把头指针向后移。  

但这题不是排序数组，是一个普通的序列。  
这里有几种方法，leetcode都有详解。
1. 暴力方法：把target-nums[i]与后面n-i项相比，看是否存在。此时复杂度为O(n^2)
2. 利用哈希表，遍历两次。在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
        然后，在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]）是否存在于表中。
        注意，该目标元素不能是 nums[i]nums[i] 本身！此时时间复杂度为O(n)，空间复杂度为O(n)
3. 利用哈希表，遍历一次。如果存在两数之和为target的话，数字是成对出现的，只是会有遍历的先后问题。所以我们可以一边
        把target - nums[i]存入哈希表，一边判断num[i]是否已经存在哈希表。此时间复杂度为O(n)，空间复杂度为O(n)。

## 两数相加
题目：[给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。](https://leetcode-cn.com/problems/add-two-numbers/description/)  
解析：这道题思路很简单，就是模拟加法的过程，有点类似于归并排序是的merge。  
但写代码的时候可以简化些写法，例如使用p1+p2+carry，而不是先将p1+p2，再判断其进位和余数。  
这样写会让思路更加清晰。  
具体解答https://leetcode-cn.com/problems/add-two-numbers/solution/  
另外，变式是说如果数字是按顺序存储在链表中，例如123：1-2-3，此时要如何相加呢？  
我的想法是，类似于《剑指offer》的反转链表，可以利用辅助空间（两个栈）。

##  无重复字符的最长子串
题目：[给定一个字符串，找出不含有重复字符的最长子串的长度。](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/)  
解析：这道题是《剑指offer》的面试题48  
其思路是这样的，利用空间来换取效率，需要一个哈希表，只需要遍历一次字符串。  
如果第i个字符没有出现过，则让curlength加一。  
如果第i个字符出现过，设第i个字符和上一次出现过的距离为d：  
    1. 如果d>curlength，说明第i个字符不在当前子串中，可以curlength加一  
    2. 如果d<=curlength，说明第i个字符在当前子串中，此时让curlength=d  
《剑指offer》上利用了动态规划的想法来讲解，和我的简易思路一致。

另外leetcode上有种“滑动窗口的解法”，其思路是，判断第i个字符是否在[j,i-1]的子串中，如果存在，则滑动窗口变成[i`+1,i];
如果不存在，则滑动窗口为[j,i]

## 最长回文子串
题目：[给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。](https://leetcode-cn.com/problems/longest-palindromic-substring/description/)  
解析：可以使用中心扩展法，找到一个中心，向两边扩展，当不是回文就退出，当是回文，则继续扩展。  
一个字符串一共有2n-1个中心，分别是n个类似于[aba]这样的字符串，和n-1个类似于[abba]这样的字符串。

## Ksum总结
Ksum表示k个数进行相加。
1. 2Sum即2个数进行相加，思路一是利用hash表，将target-a作为key，a的index作为value，存入hash中，遍历一次，即可得到答案。思路二是先对数组进行排序，然后设置双指针left和right，当\*left+\*right>0时，移动right，否则移动left。当\*left+\*right==target时，存入list。这种算法记得要处理重复元素。
2. 3Sum可以将其退化成2Sum，枚举数组里面的所有元素，让这个元素等于2Sum中的target。
3. 4Sum退化成3Sum
4. Ksum可以退化成(K-1)sum，此时复杂度是O(N^(K-1))
