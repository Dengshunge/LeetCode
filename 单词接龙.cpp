#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

/*
本题还是很有难度的，笔试的时候见过，是一种BFS的题目。
下面的链接是网络上的解释，可以理解成图
https://www.jianshu.com/p/753bd585d57e

下面的BFS使用到了队列，但速度较慢，网上有更加快捷的方法，但还理解不了。
https://leetcode.com/problems/word-ladder/discuss/40707/Easy-76ms-C%2B%2B-Solution-using-BFS
*/

class Solution 
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		set<string> List(wordList.begin(), wordList.end());//构建一个set，里面包含所有的单词，当浏览过后，就会逐一删除里面的单词
		List.insert(beginWord);
		queue<string> Que;//用于BFS的队列，里面包含下一层的单词
		Que.push(beginWord);
		for (int len = 1; !Que.empty(); ++len)//len表明是层数
		{
			for (int i = Que.size(); i >0; --i)//这里从后往前是因为Que会变化，会逐一弹出元素
			{
				//计算同一层中的所有单词
				string	word = Que.front();
				Que.pop();
				//如果找到合适的单词，就return
				if (word == endWord)
					return len;
				//删除List里面的word，只保留还未浏览的元素
				List.erase(word);
				for (int j = 0; j < word.size(); ++j)//逐一改变word里面的每一个字母
				{
					char letter = word[j];//先把原字母保留下来
					for (int k = 0; k < 26; ++k)
					{
						word[j] = 'a' + k;//然后用26个英文字母去代替
						if (List.find(word) != List.end())
						{
							//如果找到变换一个字母的单词，就加入Que，并从List中删除
							Que.push(word);
							List.erase(word);
						}
					}
					word[j] = letter;
				}
			}
		}
		return 0;
	}
};


int main() 
{
	Solution a;
	vector<string> wordList{ "hot","dot","dog","lot","log" };
	cout << a.ladderLength("hit","cog",wordList) << endl;


	system("pause");
	return 0;
}
