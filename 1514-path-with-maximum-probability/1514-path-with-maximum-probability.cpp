class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<double,int>>adj[n+1];
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0],v=edges[i][1];
            double wt=succProb[i];
            adj[u].push_back({wt,v});
            adj[v].push_back({wt,u});
        }
        priority_queue<pair<double,int>>q;
        q.push({1,start});
        double res = 0;
        vector<bool>vis(n,0);
        while(!q.empty()){
            auto wt = q.top().first;
            auto node = q.top().second;
            q.pop();
            if(node == end){
                return wt;
            }
            vis[node] = 1;
            for(auto it:adj[node]){
                if(!vis[it.second]){
                    q.push({wt*it.first,it.second});
                }
            }
        }
        return res;
    }
};