class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<(i%2==0 ? i/2 : i/2 + 1);j++){
                if(j == (i - j - 1)){
                    dp[i]+= dp[j] * dp[j];
                }
                else dp[i]+= 2 * dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};