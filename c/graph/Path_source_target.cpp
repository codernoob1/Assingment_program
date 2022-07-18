#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfs(vector<vector<int>>& graph,vector<vector<int>> &result,vector<int> &path,int u){
        path.push_back(u);
        if(u == graph.size()-1) result.push_back(path);
        else{
            for(int v:graph[u]){
                dfs(graph,result,path,v);
            }
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(graph,result,path,0);
        return result;
    }
};
void print_vector(vector<int> &v){
    cout<< "Size:"<< v.size() << endl;
    
    for(int i=0;i<v.size();i++){
             cout<< v[i] << " ";
        }
        
    }
    cout<< endl;
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> v;
    for(int i =0;i<N;i++){
       int n;
       cin >> n;
       vector<int> temp;
       for(int j =0;j<n;++j){
           int x;
           cin >> x;
           temp.push_back(x);
       }
       v.push_back(temp);
    }
    for(int i =0;i<N;i++){
        print_vector(v[i])
    }
    Solution obj;
    obj.allPathsSourceTarget(v);
    print_vector(v);

}