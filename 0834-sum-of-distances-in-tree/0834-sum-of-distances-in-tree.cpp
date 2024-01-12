class Solution {
public:
    unordered_map<int,pair<int,int>>dis;
    vector<int>ans;
    pair<int,int> dfs(int node,vector<int>adj[],vector<bool>&vis){
        vis[node] = 1;
        int nodes = 0, dist = 0;
        bool f = 0;
        for(auto it: adj[node]){
            if(!vis[it]){
                f = 1;
                auto [wt,sz] = dfs(it,adj,vis);
                if(node == 0){
                    // cout<<it<<" "<<wt<<" "<<sz<<endl;
                }
                dist += wt;
                nodes += sz;
            }
        }
        if(!f){
            dis[node] = {0,1};
            return {1,1};
        }
        else {
            dis[node] = {dist,nodes+1};
            return {dist+nodes+1,nodes+1};
        }
    }
    void dfs2(int node,int par,vector<int>adj[],vector<bool>&vis){
        vis[node] = 1;
        auto [d1,n1] = dis[node];
        auto [d2,n2] = dis[par];
        int x = d1 + (d2 - (d1+n1)) + (n2 - n1);
        ans[node] = x;
        dis[node] = {x,n2};
        for(auto it:adj[node]){
            if(!vis[it])dfs2(it,node,adj,vis);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        ans.resize(n,0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        dfs(0,adj,vis);
        // for(auto it:dis){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        // }
        ans[0] = dis[0].first ;
        vector<bool>vis1(n,0);
        vis1[0] = 1;
        for(auto it:adj[0]){
            dfs2(it,0,adj,vis1);
        }
        return ans;
    }
};