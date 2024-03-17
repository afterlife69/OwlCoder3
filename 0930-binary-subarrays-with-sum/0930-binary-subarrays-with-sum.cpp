class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i = 0, j = 0,ans = 0;
        unordered_map<int,int>mp;
        mp[0]= 1;
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            cur += nums[i];
            if(cur >= goal)
            ans += mp[cur - goal];
            mp[cur]++;
        }
        return ans;
    }
};