class Solution {
public:
    int dp[1001][1001];
    const int mod = 1e9 + 7;
    int dfs(int n,int k){
        if(n == 0)return k==0;
        if(k==0)return 1;
        if(k < 0)return 0;
        if(dp[n][k] != -1)return dp[n][k];
        int x = dfs(n-1,k);
        int y = dfs(n,k-1);
        int z = dfs(n-1,k-n);
        return dp[n][k] = (((x + y) %mod + mod) - z)%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(n,k);
    }
};