class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool vis[26];
        int ans = 0;
        for(auto it : allowed)vis[it - 'a'] = 1;
        for(auto it : words){
            int cur = 1;
            for(auto it2: it)if(!vis[it2 - 'a']){
                cur = 0;
                break;
            }
            ans += cur;
        }
        return ans;
    }
};