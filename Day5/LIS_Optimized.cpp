class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        for(auto it:nums){
            if(v.empty() || v.back() < it)v.push_back(it);
            else{
                *lower_bound(v.begin(),v.end(),it) = it;
            }
        }
        return v.size();
    }
};