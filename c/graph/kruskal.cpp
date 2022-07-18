/*
Name - Saikat Mazumder
prog name - find minimum spanning tree using kruskal algo
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int Parent[N];
int size[N];

void make(int v){
    Parent[v] = v;
    size[v] = 1;
}
int find(int v){
    if(v == Parent[v]) return v;
    //path comparison
    return Parent[v] =  find(Parent[v]);
}

void Union(int a,int b){
    a = find(a);
    b = find(b);

    if(a != b){
        //unoin by size
        if(size[a] < size[b]){
            swap(a,b);
        }
        Parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<pair <int, pair<int,int>> > edges;

    for(int i = 0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});   
    }
    sort(edges.begin(),edges.end());

    for(int i =1;i<=n; ++i){
        make(i);
    }


    int total_cost = 0;
    for(auto &edges : edges){
        int wt = edges.first;
        int u = edges.second.first;
        int v = edges.second.second;

        if(find(u) == find(v)) continue;
        Union(u,v);
        total_cost += wt;
        cout<<"nodes participate buliding in spanning tree : " << endl;
        cout << u << " " << v << endl;

    }
    cout<< "min of weight of spanning tree: "<< total_cost << endl;
}

/*
output:
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
nodes participate buliding in spanning tree : 
1 4
nodes participate buliding in spanning tree : 
1 2
nodes participate buliding in spanning tree : 
3 2
nodes participate buliding in spanning tree : 
5 1
nodes participate buliding in spanning tree : 
2 6
min of weight of spanning tree: 17
*/