#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,unordered_map<int,vector<int>>&adj,vector<bool>&vis,int prev){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it] && it!=prev)return 1;
        else if(!vis[it]){
            if(dfs(it,adj,vis,node))return 1;
        }
    }
    return 0;
}
void L(){
    int V;
    cin>>V;
    vector<int>v(V);
    for(int i=0;i<V;i++){
        cin>>v[i];
    }
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            if(v[i] & v[j]){
                adj[v[i]].push_back(v[j]);
                adj[v[j]].push_back(v[i]);
            }
        }
    }
    vector<bool>vis(V);
    for(auto it:v){
        if(!vis[it]){
            if(dfs(it,adj,vis,-1)){
                cout<<"Cycle"<<endl;
                return ;
            }
        }
    }
    cout<<"No Cycle"<<endl;
}
int main(){
    L();
}