#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <time.h>
#include "linearlist.cpp"

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle)
	{
		if (needle.size() == 0)
			return 0;
		vector<int>next = GetNext(needle);
		int i = 0;//S的下标
		int j = 0;//P的下标
		int s_len = haystack.size(), p_len = needle.size();
		while (i<s_len&&j<p_len)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if (j == p_len)
			return i - j;
		return -1;
	}
private:
	vector<int> GetNext(string P)
	{
		int P_len = P.size();
		vector<int>next(P_len, -1);
		int i = 0, j = -1;
		while (i<P_len - 1)
		{
			if (j == -1 || P[i] == P[j])
			{
				i++;
				j++;
				if (P[i] != P[j])
					next[i] = j;
				else
					next[i] = next[j];
			}
			else
				j = next[j];
		}
		return next;
	}
};


int main()
{
	Solution a;
	
	string S = "aaaaa";
	string P = "bba";
	cout << a.strStr(S, P) << endl;


	system("pause");
}

