class Solution {
public:
    int dp[1001];
    int dfs(int i, vector<vector<int>>&v, int W){
        if(i == v.size())return 0;
        if(dp[i] != -1)return dp[i];
        int w = W, mxi = 0;
        int ans = 1e9;
        for(int j=i;j<v.size();j++){
            if((w - v[j][0]) < 0)break;
            mxi = max(mxi, v[j][1]);
            ans = min(ans, dfs(j+1,v,W)+mxi);
            w -= v[j][0];
        }
        return dp[i] = ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return dfs(0, books,shelfWidth);
    }
};