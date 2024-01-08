class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<int,int>>dp(nums.size());
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff = (1LL)*nums[i] - (1LL)*nums[j];
                if(diff <= INT_MIN or diff >= INT_MAX)continue;
                dp[i][diff]++;
                if(dp[j].count(diff)){
                    ans+=dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
            }
        }
        return ans;
    }
};