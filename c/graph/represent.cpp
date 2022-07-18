#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin >> n >> m;

    //declare the adjancey matrix
    int adj[n+1][n+1];

    for(int i = 0;i<m;i++){
        int u,v;
        cin >> u >>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}