#define pi pair<int,int>
#define vll vector<int>
#define ll int
class Solution {
public:
    map<vector<int>, pair<int,int>>dp;
    pi dfs(int i, int j, bool f, vll &v){
        if(i > j)return {0,0};
        if(dp.find({i,j,f}) != dp.end())return dp[{i,j,f}];
        if(!f){
            pi a = dfs(i+1,j,!f,v);
            pi b = dfs(i,j-1,!f,v);
            ll l1 = a.first, h1 = a.second, l2 = b.first, h2 = b.second;
            if(l1 + v[i] > l2+v[j]){
                return dp[{i,j,f}] = {l1+v[i], h1};
            }
            else return dp[{i,j,f}] = {l2+v[j], h2};
        }
        else{
            pi a = dfs(i+1,j,!f,v);
            pi b = dfs(i,j-1,!f,v);
            ll l1 = a.first, h1 = a.second, l2 = b.first, h2 = b.second;
            if(h1 + v[i] > h2+v[j]){
                return dp[{i,j,f}] = {l1, h1+v[i]};
            }
            else return dp[{i,j,f}] = {l2, h2+v[j]};
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        auto ans = dfs(0, nums.size() -1, 0, nums);
        return ans.first >= ans.second;
    }
};