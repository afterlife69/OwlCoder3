class Solution {
public:
    // int dfs(int i, string & s){
    //     if(i == s.size())return 1;
    //     int ans = dfs(i+1,s), k = 0;
    //     for(int j = i ; j < s.size(); i++){
    //         if(s[j] == s[i + k]){
    //             ans += 1 + dfs(j + 1, s);
    //         }
    //         k++;
    //     }
    //     return ans;
    // }
    int pal(int i,int j,string &s){
        int c = 0;
        while(i >= 0 && j < s.size()){
            if(s[i--]!=s[j++])return c;
            c++;
        }
        return c;
    }
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            ans += pal(i,i,s) + pal(i,i+1,s);
        }
        return ans;
    }
};