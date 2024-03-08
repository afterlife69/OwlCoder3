class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp,mp2;
        int ans = 0;
        for(auto it : nums){
            mp[it]++;
            mp2[mp[it]]++;
            ans = max(ans,mp[it]);
        }
        return mp2[ans] * ans;
    }
};