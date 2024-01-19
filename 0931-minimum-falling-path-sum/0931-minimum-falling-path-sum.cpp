class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& dp) {
        int n = dp.size(), m = dp[0].size();
        if(n == 1)return *min_element(dp[0].begin(),dp[0].end());
        int ans = 1e9;
        for(int i=1;i<n;i++){
            for(int j = 0;j<m;j++){
                int l = (j == 0) ? 1e9 : dp[i-1][j-1];
                int mid = dp[i-1][j];
                int r = (j == m-1) ? 1e9 : dp[i-1][j+1];
                dp[i][j] = dp[i][j] + min({l,mid,r});
                if(i == n-1)ans = min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};