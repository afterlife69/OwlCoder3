class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int>mp;
        for(auto it: s){
            mp[it]++;
        }
        int ans = 0;
        for(auto it: t){
            if(mp.find(it) == mp.end())ans++;
            else{
                if(mp[it] != 0)mp[it]--;
                else ans++;
            }
        }
        return ans;
    }
};