class Solution {
public:
    int ma=0;
int dp[1001][1001];
 int dfs(vector<int>&nums,int tar,int ind)
{
    if(ind>=nums.size() or tar==0)
    {
        if(tar==0)return 0;
        return -1e9;
    }
    if(dp[ind][tar]!=-1)return dp[ind][tar];
    int x=-1e9,y=-1e9,res=0;
    if(tar-nums[ind]>=0)x=dfs(nums,tar-nums[ind],ind+1)+1;
    y=dfs(nums,tar,ind+1);
    res=max(x,y);
    return dp[ind][tar]=res;
}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {

        memset(dp,-1,sizeof(dp));
       int res= dfs(nums,target,0);
       return res>0?res:-1;
    }
};