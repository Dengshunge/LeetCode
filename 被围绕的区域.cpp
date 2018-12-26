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
将边界的'O'和与其相连的'O'替换成'S'
然后遍历搜索，将'O'替换成'X'
最后再遍历搜索，将'S'提出按成'O'。
时间复杂度是O(mn)
*/


class Solution 
{
public:
	void solve(vector<vector<char>>& board) 
	{
		m = board.size();
		if (!m)
			return;
		n = board[0].size();
		if (!n)
			return;
		//第一行和最后一行
		for (int i = 0; i < n; ++i)
		{
			if (board[0][i] == 'O')
				change(board, 0, i, 'O', 'S');
			if (board[m - 1][i] == 'O')
				change(board, m - 1, i, 'O', 'S');
		}
		//第一列和最后一列
		for (int i = 0; i < m; ++i)
		{
			if (board[i][0] == 'O')
				change(board, i, 0, 'O', 'S');
			if (board[i][n - 1] == 'O')
				change(board, i, n - 1, 'O', 'S');
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				if (board[i][j] == 'O')
					board[i][j] = 'X';
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				if (board[i][j] == 'S')
					board[i][j] = 'O';
		}
	}



	void change(vector<vector<char>>& board,int x,int y,const char beChanged, const char toChange)
	{
		board[x][y] = toChange;
		if (x > 0 && board[x - 1][y] == beChanged)
			change(board, x - 1, y, beChanged, toChange);
		if (x < m - 1 && board[x + 1][y] == beChanged)
			change(board, x + 1, y, beChanged, toChange);
		if (y > 0 && board[x][y - 1] == beChanged)
			change(board, x, y - 1, beChanged, toChange);
		if (y < n - 1 && board[x][y + 1] == beChanged)
			change(board, x, y + 1, beChanged, toChange);
	}
private:
	int m = 0;
	int n = 0;
};


int main() 
{
	vector<vector<char>> board{ {'x','x', 'x', 'x'},{ 'x','o', 'o', 'x' } ,{ 'x','x', 'o', 'x' } ,{ 'x','o', 'x', 'x' } };
	Solution a;
	a.solve(board);
	for (auto m : board)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
