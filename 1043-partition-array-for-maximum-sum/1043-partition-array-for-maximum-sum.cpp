class Solution {
public:
    int dp[501];
    int dfs(int i,int k,vector<int>&v){
        if(i == v.size())return 0;
        if(dp[i] != -1)return dp[i];
        int mx = 0;
        int ans = 0;
        for(int j=i;j<v.size() && ((j - i + 1) <= k);j++){
            mx = max(mx, v[j]);
            ans = max(ans, dfs(j+1,k,v) + ((j - i + 1) * mx));
        }
        return dp[i] = ans;
    }
    // [1,15,7,9,2,5,10]
    //  0 1  2 3 4 5 6, 3
    //  15 15 15
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,k,arr);
    }
};