#define ll long long
class Solution {
public:
    ll dp[1001][1001];
    const int mod = 1e9 + 7;
    ll dfs(int n,int k){
        if(k == 0)return 1;
        if(n < 0 || k < 0)return 0;
        if(dp[n][k] != -1)return dp[n][k];
        ll ans = 0;
        for(int i=0;i<n;++i){
            if(k - i >= 0)ans += (dfs(n-1,k-i) % mod);
            else break;
        }
        return dp[n][k] = ans % mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(n,k) % mod;
    }
};