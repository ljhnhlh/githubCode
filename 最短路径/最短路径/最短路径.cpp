// 最短路径.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#define infinite 10000

using namespace std;
struct edge
{
	char end;
	int len;
};
struct node {
	char character;
	vector<edge> edge_set;
	int len;
	char prev;
};

vector<node> shortestDistance(vector<node>& node_set,char ori_node);

int main()
{
	vector<node> node_set;
	for (int i = 0; i < 6; i++)
	{
		cout << "node " << i << endl;
		node n;
		cin >> n.character;
		n.len = infinite;
		n.prev = n.character;
		char end;
		cin >> end;
		while (end != '0')
		{
			edge e;
			int len;
			cin >> len;
			e.end = end;
			e.len = len;
			n.edge_set.push_back(e);
			cin >> end;
		} 
		cout << "one node end,please continue" << endl;
		node_set.push_back(n);
	}
	cout << "please input the original node" << endl;
	char ori_node;
	cin >> ori_node;
	vector<node> D = shortestDistance(node_set, ori_node);
	for (int i = 0; i < D.size(); i++)
	{
		cout << D[i].character << endl;
	}
	cin >> ori_node;
	return 0;
}

vector<node> shortestDistance(vector<node>& node_set, char ori_node) 
{
	vector<node> D;
	vector<node> P;
	for (int i = 0; i < node_set.size(); i++)
	{
		if (node_set[i].character == ori_node)
		{
			D.push_back(node_set[i]);
		}
		else
		{
			P.push_back(node_set[i]);
		}
	}
	int index = 0;
	D[0].len = 0;
	char end;
	int len;
	while (P.size())
	{
		//更新节点的最短路径
		for (int i = 0; i < D[index].edge_set.size(); i++)
		{
			end = D[index].edge_set[i].end;
			len = D[index].edge_set[i].len;
			for (int j = 0; j < P.size(); j++)
			{
				if (end == P[j].character)
				{
					int temp = D[index].len + len;
					if (temp < P[j].len)
					{
						P[j].len = temp;
						P[j].prev = end;
					}	
					break; 
				}
			}
		}
		int min_dis = infinite;
		vector<node>::iterator it, temp;
		for (it = P.begin(); it != P.end(); it++)
		{
			if ((*it).len < min_dis)
			{
				temp = it;
				min_dis = (*it).len;
			}
		}
		D.push_back(*temp);
		P.erase(temp);
		index++;
	}
	return D;
}