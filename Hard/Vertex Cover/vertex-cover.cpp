//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dfs(int i,vector<int>adj[],vector<int>&deg,int v){
        if(i == deg.size() || v == 0)return v == 0 ? 0 : 1e9;
        for(auto it : adj[i])deg[it]--;
        int left = dfs(i+1,adj,deg,v - deg[i]) + 1;
        for(auto it : adj[i])deg[it]++;
        int rig = dfs(i+1,adj,deg,v);
        return min(left, rig);
    }
    int vertexCover(int n, vector<pair<int, int>> &edges) {
        vector<int>adj[n + 1],deg(n+1);
        int M = edges.size(), cur = 0;
        for(int i=0;i<M;i++){
            auto it = edges[i];
            int u = it.first, v = it.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        cur = edges.size();
        return dfs(1,adj,deg,cur);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends