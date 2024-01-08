class Solution {
public:
    // int dp[1001][2001];
    int dfs(int i,int j,int k,vector<vector<int>>&piles,vector<vector<vector<int>>>&dp){
        if(i == piles.size())return 0;
        if(k == 0)return 0;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int left = dfs(i+1,0,k,piles,dp),rig = 0;
        if(j < piles[i].size())
        rig = dfs(i,j+1,k-1,piles,dp)+piles[i][j];
        return dp[i][j][k] = max(left,rig);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int mx = 0;
        for(auto it:piles){
            int x = it.size();
            mx = max(mx,x);
        }
        vector<vector<int>>d1(mx+1,vector<int>(k+1,-1));
        vector<vector<vector<int>>>dp(piles.size()+1,d1);
        return dfs(0,0,k,piles,dp);
    }
};