/*
Name: Aniket jaiswal 
Q: Write a C/C++ program to find a spanning tree from a connected graph by using Depth First Search. 
*/

#include <iostream>
#include <vector>
#include <list>
#include<queue>
using namespace std;

class Graph
{
    int n;

    vector<list<int>> adj_list;
    vector<list<int>> span_tree;
    vector<bool> visited;

public:
    Graph(int n)
    {
        this->n = n;
        adj_list.resize(n);
        span_tree.resize(n);
        for (int i = 0; i < n; i++)
        {
            adj_list[i].push_back(i);
            span_tree[i].push_back(i);
        }
        visited.resize(n, false);
    }

    void add_edges()
    {
        int src, dest;
        
        cout << "Enter source vertex(Enter -1 to end): ";
        cin >> src;
        while (src != -1 && src < n)
        {
            cout << "Enter all destinations of vertex " << src << " (Enter -1 to finish): ";
            cin >> dest;
            while (dest != -1 && dest < n)
            {
                adj_list[src].push_back(dest);
                cin >> dest;
            }
            cout << "Enter source vertex(Enter -1 to end): ";
            cin >> src;
        }
    }

    void disp_adj()
    {
        for (auto it : adj_list)
        {
            for (auto it2 : it)
            {
                if (it2 == it.front())
                    cout << it2 << "->";
                else
                    cout << it2 << " ";
            }
            cout << endl;
        }
    }

    void spanning_tree(int vertex)
    {
        visited[vertex] = true;
        //dfs(vertex);
        bfsOfGraph(vertex,adj_list);
        for (auto it : span_tree)
        {
            for (auto it2 : it)
            {
                if (it2 == it.front())
                    cout << it2 << "->";
                else
                    cout << it2 << " ";
            }
            cout << endl;
        }
    }

    void dfs(int vertex)
    {
        for (auto it : adj_list[vertex])
        {
            if (!visited[it])
            {
                span_tree[vertex].push_back(it);
                visited[it] = true;
                dfs(it);
            }
        }
    }
    vector<int> bfsOfGraph(int vertex,vector<list<int>> adj_list){
        vector<int> bfs;
        vector<int> vis(vertex,0);

        for(int i =0;i<vertex;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it: adj_list[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return bfs;
    }
};

int main()
{
    int n, src, dest, start;
    cout << "Enter the no. of vertices: ";
    cin >> n;
    Graph graph(n);

    cout << "Enter edges- " << endl;
    graph.add_edges();

    cout << "\nAdjacency list for given graph: " << endl;
    graph.disp_adj();

    cout << "Enter the starting point in graph for spanning tree(0->" << n - 1 << "):";
    cin >> start;

    cout << "\nAdjacency list for Spanning tree using DFS starting from vertex " << start << ":" << endl;
    graph.spanning_tree(start);

    return 0;
}