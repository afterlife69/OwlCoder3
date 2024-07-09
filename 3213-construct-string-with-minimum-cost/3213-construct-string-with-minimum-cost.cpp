class Trie{
public:
    Trie* lnk[26] = {nullptr};
    int cost;
    Trie(){
        cost = -1;
    }
};
class Solution {
public:
    Trie * root = new Trie();
    int dp[50001];
    int dfs(int i, string &s){
        if(i == s.size())return 0;
        if(dp[i] != -1)return dp[i];
        int ans = 1e9;
        Trie * t = root;
        for(int j=i;j<s.size();j++){
            if(!t->lnk[s[j] - 'a'])break;
            t = t->lnk[s[j] - 'a'];
            if(t->cost != -1)ans = min(ans, dfs(j+1,s) + t->cost);
        }
        return dp[i] = ans;
    }
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        for(int i=0;i<words.size();i++){
            Trie * t = root;
            for(auto it2 : words[i]){
                if(!t->lnk[it2 - 'a'])t->lnk[it2 - 'a'] = new Trie();
                t = t->lnk[it2 - 'a'];
            }
            t->cost = t->cost == -1 ? costs[i] : min(t->cost, costs[i]); 
        }
        memset(dp, -1 ,sizeof(dp));
        int ans = dfs(0, target);
        return ans >= 1e9 ? -1 : ans;
    }
};