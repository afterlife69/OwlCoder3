class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int n = A.size(), m = A[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                A[i][j] += A[i][j-1];
            }
        }
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=i;j<m;j++){
                int cur = 0;
                mp = {{0,1}};
                for(int k=0;k<n;k++){
                    cur += (A[k][j] - (i > 0 ? A[k][i-1] : 0));
                    ans += (mp.find(cur - target) != mp.end() ? mp[cur - target] : 0);
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};