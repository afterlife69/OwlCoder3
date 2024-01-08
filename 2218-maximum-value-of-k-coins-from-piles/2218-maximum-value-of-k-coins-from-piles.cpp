class Solution {
public:
    int dp[1000][2001];
    int dfs(int i,int k,vector<vector<int>>&piles){
        if(i == piles.size())return 0;
        if(dp[i][k] != -1)return dp[i][k];
        int ans = 0,run = 0;
        ans = max(ans,dfs(i+1,k,piles));
        for(int j=0; j<piles[i].size() && j < k;j++){
            run += piles[i][j];
            ans = max(ans, dfs(i+1,k-j-1,piles) + run);
        }
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,k,piles);
    }
};