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