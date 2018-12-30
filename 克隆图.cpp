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
克隆一张图，与遍历一张图的方法类似。
先创建一个visited，用于表示结点值label与结点坐标的对应关系。可以用于读取重复节点
当遍历当前结点的邻接点时，首先在visited中查找，如果找到，则在neighbor中直接压入；如果不存在，在new一个，然后插入visited和neighbor中。
接下来，继续得带，类似于深度遍历DFS
*/

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
	{
		if (!node)
			return nullptr;
		UndirectedGraphNode *Newnode = new UndirectedGraphNode(node->label);
		visited.insert(make_pair(node->label, Newnode));
		cloneGraph(node, Newnode);
		return Newnode;
	}

private:
	map<int, UndirectedGraphNode *> visited;
	void cloneGraph(UndirectedGraphNode *node, UndirectedGraphNode *Newnode)
	{
		for (auto beg = node->neighbors.begin(); beg < node->neighbors.end(); ++beg)
		{
			auto it = visited.find((*beg)->label);
			if (it != visited.end())
			{
				Newnode->neighbors.push_back(it->second);
			}
			else
			{
				UndirectedGraphNode *p = new UndirectedGraphNode((*beg)->label);
				visited.insert(make_pair((*beg)->label, p));
				Newnode->neighbors.push_back(p);
				cloneGraph(*beg, p);
			}
		}
	}
};


int main() 
{
	UndirectedGraphNode node1{ 0 };
	UndirectedGraphNode node2{ 1 };
	UndirectedGraphNode node3{ 2 };
	node1.neighbors.push_back(&node2);
	node1.neighbors.push_back(&node3);
	node2.neighbors.push_back(&node3);
	node3.neighbors.push_back(&node3);

	Solution a;
	UndirectedGraphNode *p = a.cloneGraph(&node1);
	cout << p->label << endl;


	system("pause");
	return 0;
}
