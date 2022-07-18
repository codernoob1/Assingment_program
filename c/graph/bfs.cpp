/*
Name - Saikat Mazumder
prog Name - bfs of spanning tree
*/

#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int V; 


	vector<list<int>> adj;
public:
	Graph(int V); 

	void addEdge(int v, int w);

	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); 
}

void Graph::BFS(int s)
{
	vector<bool> visited;
	visited.resize(V,false);

	list<int> queue;

	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (auto it: adj[s])
		{
			if (!visited[it])
			{
				visited[it] = true;
				queue.push_back(it);
			}
		}
	}
}

int main()
{
	Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(4,3);
    g.addEdge(4,2);
    g.addEdge(2,4);

	cout << "Breadth first Search \n";
	g.BFS(0);
    cout<<"\n";

	return 0;
}
/*
output:
Breadth first Search 
0 1 3 4 2 

*/