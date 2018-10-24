#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
#include <unordered_map>
#include <functional>
using namespace std;

/*
典型的回溯法，设置一个标志矩阵来判断该位置是否访问过，但需要记得将标志位改回去
LeetCode上对此方法进行了改进，取消了建立标志位，直接再board矩阵中将该元素修改成'/0'，这样对比的时候，就不会有重复相同的了。
*/

class Solution
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		m = board.size();
		n = board[0].size();
		vector<vector<bool>> flag(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (exist(board, word, flag, 0, i, j))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string &word, vector<vector<bool>> &flag, int start, int x, int y)
	{
		if (start == word.size())
			return true;
		bool hasPath = false;
		if (x >= 0 && x < m&&y >= 0 && y < n && !flag[x][y] && board[x][y] == word[start])
		{
			++start;
			flag[x][y] = true;
			hasPath = exist(board, word, flag, start, x, y - 1) || exist(board, word, flag, start, x, y + 1) ||
				exist(board, word, flag, start, x - 1, y) || exist(board, word, flag, start, x + 1, y);
			if (!hasPath)
			{
				--start;
				flag[x][y] = false;
			}
		}
		return hasPath;
	}

private:
	int m = 0, n = 0;
};

class Solution2
{
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (exist(board, word, 0, i, j))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool exist(vector<vector<char>>& board, string &word, int start, int x, int y)
	{
		if (start == word.size())
			return true;
		bool hasPath = false;
		if (x >= 0 && x < m&&y >= 0 && y < n && board[x][y] == word[start])
		{
			++start;
			char t = board[x][y];
			board[x][y] = '/0';
			hasPath = exist(board, word, start, x, y - 1) || exist(board, word, start, x, y + 1) ||
				exist(board, word, start, x - 1, y) || exist(board, word, start, x + 1, y);
			if (!hasPath)
			{
				--start;
				board[x][y] = t;
			}
		}
		return hasPath;
	}

private:
	int m = 0, n = 0;
};

int main() 
{
	Solution2 a;
	vector<vector<char>> board{ { 'A','B','C','E' },
								{ 'S','F','E','S' },
								{ 'A','D','E','E' } };
	cout << boolalpha << a.exist(board, "SEE") << endl;


	system("pause");
	return 0;
}



