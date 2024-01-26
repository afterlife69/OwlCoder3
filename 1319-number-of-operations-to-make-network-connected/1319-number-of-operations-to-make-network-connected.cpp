class Solution {
public:
    unordered_map<int,int>par, rank;
    int findd(int x){
        if(par[x] == x)return x;
        return par[x] = findd(par[x]);
    }
    void unionn(int u,int v){
        u = findd(u);
        v = findd(v);
        if(rank[u] > rank[v]){
            par[v] = u;
            rank[u] += rank[v];
        }
        else{
            par[u] = v;
            rank[v] += rank[u];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i=0;i<n;i++){
            par[i] = i;
            rank[i]++;
        }
        int cnt = 0;
        for(auto it : connections){
            int u = it[0], v = it[1];
            if(findd(u) == findd(v))cnt++;
            else unionn(u,v);
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(findd(i));
        }
        int need = s.size() - 1;
        if(need > cnt)return -1;
        return need;
    }
};