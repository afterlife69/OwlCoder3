class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0;
        k++;
        while(j < nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]] > 1)return 1;
            if((j - i + 1) == k){
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return 0;
    }
};