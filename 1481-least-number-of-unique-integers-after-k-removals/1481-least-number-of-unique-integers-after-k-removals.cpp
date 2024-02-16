class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        vector<int>v;
        for(auto it : arr)mp[it]++;
        for(auto it : mp)v.push_back(it.second);
        sort(v.begin(),v.end());
        int ans = mp.size();
        for(auto it : v){
            if(k - it < 0)break;
            else{
                k -= it;
                ans--;
            }
        }
        return ans;
        
    }
};