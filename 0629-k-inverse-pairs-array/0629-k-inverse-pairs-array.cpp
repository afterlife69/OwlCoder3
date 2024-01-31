class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int Fun(int n , int k){
        //base case 
        if(k <= 0)return k==0;
        if(dp[n][k]!=-1)return dp[n][k]%mod;
        int ans = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(k - i >= 0)ans = (ans % mod+ Fun(n-1,k-i)%mod)%mod;
        }
        return dp[n][k]= ans%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return Fun(n,k);
        
    }
};