//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>adj[n+1],ind(n+1);
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            if(u == v)return {};
            adj[v].push_back(u);
            ind[u]++;
        }
        queue<int>q;
        for(int i =0;i<n;i++){
            if(ind[i] == 0)q.push(i);
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it: adj[node]){
                ind[it]--;
                if(ind[it] == 0)q.push(it);
            }
        }
        // for(auto it : res)cout<<it<<" ";
        if(res.size() != n)return {};
        return res;
    }
};


//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends