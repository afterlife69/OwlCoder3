class Solution {
public:
    int dp[101][101][101];
    const int mod = 1e9 + 7;
    int dfs(int i,int n, int m,int prof, vector<int>& group, vector<int>& profit){
        if(i == group.size())return prof >= m;
        if(n == 0)return prof >= m;
        if(dp[i][n][prof] != -1)return dp[i][n][prof];
        int left = 0;
        if((n - group[i]) >= 0)left = ((left % mod) + dfs(i+1,n-group[i],m,min(m,prof + profit[i]),group,profit) % mod)%mod;
        left = ((left % mod) + (dfs(i+1,n,m,prof,group,profit)%mod))%mod;
        return dp[i][n][prof] = left%mod;
    }
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,n,m,0,group,profit);
    }
};