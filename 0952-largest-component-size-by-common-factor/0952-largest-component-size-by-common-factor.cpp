class Solution {
public:
    unordered_map<int,int>par,rank;
    int findd(int x){
        if(par[x] == x)return x;
        return par[x] = findd(par[x]);
    }
    void unionn(int u,int v){
        u = findd(u);
        v = findd(v);
        if(u == v)return;
        if(rank[u] >= rank[v]){
            par[v] = u;
            rank[u] += rank[v];
        } 
        else{
            par[u] = v;
            rank[v] += rank[u];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        for(auto it : nums){
            par[it] = it;
            rank[it] = 1;
        }
        unordered_map<int,int> mp;
        for(auto it : nums){
            for(int i=2;i<=sqrt(it);i++){
                if(it%i == 0){
                    if(mp[i] != 0)unionn(it,mp[i]);
                    mp[i] = it;
                    if(mp[it/i] != 0)unionn(it,mp[it/i]);
                    mp[it/i] = it;
                }
            }
            if(mp[it] != 0)unionn(it,mp[it]);
            mp[it] = it;
        }
        for(auto it : nums)findd(it);
        int ans = 1;
        for(auto it : rank)ans = max(ans,it.second);
        return ans;
    }
};