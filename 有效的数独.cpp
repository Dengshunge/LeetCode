#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <utility>
using namespace std;

/*
我的方法是利用暴力解法，每一行、每一列和每一个小正方形都比较一次。
由于没用技巧，这种写法显得有些臃肿。
网上有种写法，利用了下标法。每一行，每一列和每个小正方形都有9个元素，利用下标法，可以节省一些比较次数。
下标法的难点是如何表示小正方形中的行号和列号，此时只能通过举例子来找规律。
https://www.cnblogs.com/ganganloveu/p/4170632.html
*/

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		return checkRow(board) && checkColumn(board) && checkSquare(board);
	}

	//检查每一行
	bool checkRow(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; ++i)
		{
			set<char> m;
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] != '.')
				{
					if (m.find(board[i][j]) == m.end())
						m.insert(board[i][j]);
					else
						return false;
				}
			}
		}
		return true;
	}
	
	//检查每一列
	bool checkColumn(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; ++i)
		{
			set<char> m;
			for (int j = 0; j < 9; ++j)
			{
				if (board[j][i] != '.')
				{
					if (m.find(board[j][i]) == m.end())
						m.insert(board[j][i]);
					else
						return false;
				}
			}
		}
		return true;
	}

	//检查每一个正方形
	bool checkSquare(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; i+=3)
		{
			for (int j = 0; j < 9; j += 3)
			{
				set<char> m;
				for (int x = 0; x<3; ++x)
					for (int y = 0; y < 3; ++y)
					{
						if (board[i + x][j + y] != '.')
						{
							if (m.find(board[i + x][j + y]) == m.end())
								m.insert(board[i + x][j + y]);
							else
								return false;
						}
					}
			}
		}
		return true;
	}
};



int main()
{
	vector<vector<char>>board{ { '8','3','.','.','7','.','.','.','.' },
	{ '6','.','.','1','9','5','.','.','.' },
	{ '.','9','8','.','.','.','.','6','.' },
	{ '8','.','.','.','6','.','.','.','3' },
	{ '4','.','.','8','.','3','.','.','1' },
	{ '7','.','.','.','2','.','.','.','6' },
	{ '.','6','.','.','.','.','2','8','.' },
	{ '.','.','.','4','1','9','.','.','5' },
	{ '.','.','.','.','8','.','.','7','9' } };
	//Solution a;
	//cout << boolalpha << a.checkRow(board) << endl;
	//cout << boolalpha << a.checkColumn(board) << endl;
	//cout << boolalpha << a.checkSquare(board) << endl;
	//cout << boolalpha << a.isValidSudoku(board) << endl;
	int i = 1;
	cout << i / 3 * 3 << endl;


	system("pause");

}

