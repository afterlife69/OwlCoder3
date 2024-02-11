class Solution {
public:
    int dp[71][71][71];
    int dfs(int r,int c1,int c2,vector<vector<int>>&v){
        if(c1 < 0 || r == v.size() || c1 == v[0].size() || c2 == v[0].size() || c2 < 0)return 0;
        if(dp[r][c1][c2] != -1)return dp[r][c1][c2];
        int x1 = dfs(r+1,c1-1,c2-1,v);
        int x2 = dfs(r+1,c1-1,c2,v);
        int x3 = dfs(r+1,c1-1,c2+1,v);
        int x4 = dfs(r+1,c1,c2-1,v);
        int x5 = dfs(r+1,c1,c2,v);
        int x6 = dfs(r+1,c1,c2+1,v);
        int x7 = dfs(r+1,c1+1,c2-1,v);
        int x8 = dfs(r+1,c1+1,c2,v);
        int x9 = dfs(r+1,c1+1,c2+1,v);
        int add = v[r][c1] + v[r][c2];
        if(c1 == c2)add/=2;
        return dp[r][c1][c2] = max({x1,x2,x3,x4,x5,x6,x7,x8,x9}) + add;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,grid[0].size()-1,grid);
    }
};