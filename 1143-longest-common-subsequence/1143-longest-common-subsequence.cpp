class Solution {
public:
    int dp[1001][1001];
    int dfs(int i,int j,string &s,string &t){
        if(i == s.size() || j == t.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i] == t[j])return dp[i][j] = 1 + dfs(i+1,j+1,s,t);
        int left = dfs(i+1,j,s,t);
        int right = dfs(i,j+1,s,t);
        return dp[i][j] = max(left,right);
    }
    int longestCommonSubsequence(string &s, string &t) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,s,t);
    }
};