class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>pref(nums.size()),suff(nums.size()),ans;
        pref[0] = nums[0];
        int n = nums.size();
        suff.back() = nums.back();
        for(int i=1;i<nums.size();i++){
            pref[i] = pref[i-1] * nums[i];
            suff[n-i-1] = suff[n-i] * nums[n - i - 1];
        }
        for(int i=0;i<n;i++){
            int left = (i - 1) < 0 ? 1 : pref[i-1];
            int rig = (i + 1) >= n ? 1 : suff[i+1];
            ans.push_back(left * rig);
        }
        return ans;
    }
};