class Solution {
public:
    int dp[10001];
    int dfs(int n){
        if(n == 0)return 0;
        if(n < 0)return 1e9;
        
        if(dp[n] != -1)return dp[n];
        int ans = 1e9;
        for(int i=1;i*i <= n;i++){
            ans = min(ans, dfs(n - (i*i)) + 1);
        }
        return dp[n] =  ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(n);
    }
};