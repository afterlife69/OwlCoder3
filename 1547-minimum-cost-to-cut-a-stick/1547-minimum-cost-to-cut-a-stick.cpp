class Solution {
public:
    int dp[101][101];
    int dfs(int l,int r,int ind,int j,vector<int>&v){
        if(ind == j)return 0;
        if(dp[ind][j] != -1)return dp[ind][j];
        int ans = 1e9;
        for(int i=ind;i<j;i++){
            int left = dfs(l,v[i],ind,i,v);
            int rig = dfs(v[i],r,i+1,j,v);
            ans = min(ans,left + rig + (r - l));
        }
        return dp[ind][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(dp,-1,sizeof(dp));
        return dfs(0,n,0,cuts.size(),cuts);
    }
};