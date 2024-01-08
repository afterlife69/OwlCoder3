class Solution {
public:
    int dp[1001][1001];
    int dfs(int i,int tar,vector<int>&v){
        if(i == v.size())return ((tar == 0)?0:-1e9);
        if(tar == 0)return dp[i][tar] = 0;
        if(tar < 0)return dp[i][tar] = -1e9;
        if(dp[i][tar]!=-1)return dp[i][tar];
        int ans = -1e9;
        if((tar - v[i]) >= 0)ans = max(ans,dfs(i+1,tar-v[i],v))+1;
        ans = max(ans,dfs(i+1,tar,v));
        return dp[i][tar] = ans;
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int res = dfs(0,target,nums);
        return res < 0 ? -1 : res;
    }
};