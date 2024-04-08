#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[20001][6];
    ll dfs(int cur, int n){
        if(n == 0)return 1;
        if(dp[n][cur] != -1)return dp[n][cur];
        if(cur == 1)return dp[n][cur] = dfs(2,n-1) % mod;
        if(cur == 2)return dp[n][cur] = (dfs(1,n-1)%mod + dfs(3,n-1)%mod)%mod;
        if(cur == 3)return dp[n][cur] = (dfs(1,n-1)%mod + dfs(2,n-1)%mod + dfs(4,n-1)%mod + dfs(5,n-1)%mod)%mod;
        if(cur == 4)return dp[n][cur] = (dfs(3,n-1)%mod + dfs(5,n-1)%mod);
        return dp[n][cur] = dfs(1,n-1)%mod; 
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=5;i++){
            ans = (ans%mod + dfs(i,n-1)%mod)%mod;
        }
        return ans;
    }
};