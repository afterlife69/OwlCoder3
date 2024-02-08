class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        memset(dp,1e9,sizeof(dp));
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int mn = 1e9;
            for(int j=1;j*j <= i;j++){
                int cur = j*j;
                if(i - cur >= 0){
                   mn = min(mn,dp[i-cur]);
                }
            }
            dp[i] = mn + 1;
        }
        return dp[n] ;
    }
};