class Solution {
public:
    int dp[1001];
    int dfs(int cur,vector<int>&v){
        if(cur == 0)return 1;
        if(cur < 0)return 0;
        if(dp[cur] != -1)return dp[cur];
        int ans = 0;
        for(auto it : v){
            // if(cur - it < 0)break;
            ans += dfs(cur-it,v);
        }
        return dp[cur] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        // sort(nums.begin(),nums.end());
        return dfs(target,nums);
    }
};