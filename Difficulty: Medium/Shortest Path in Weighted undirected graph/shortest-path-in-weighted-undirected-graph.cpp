//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>res;
    void dfs(int node, vector<pair<int,int>>adj[],vector<bool>&v,vector<int>&dis){
        v[node] = 1;
        for(auto it : adj[node]){
            if(!v[it.first] && dis[node] == dis[it.first] + it.second){
                dfs(it.first,adj,v,dis);
                break;
            }
        }
        res.push_back(node + 1);
    }
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(auto it : edges){
            int u = it[0] - 1, v = it[1] - 1, w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>dist(n, 1e9);
        vector<bool>vis(n);
        dist[0] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, 0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] < wt)continue;
            for(auto it : adj[node]){
                if(dist[it.first] > dist[node] + it.second){
                    dist[it.first] = dist[node] + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        if(dist[n-1] == 1e9)return {-1};
        vis = vector<bool>(n);
        res.push_back(dist[n-1]);
        dfs(n-1,adj,vis,dist);
        // for(auto it : res)cout << it << " ";
        // cout << '\n';
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends