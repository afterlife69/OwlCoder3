class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>ind(n+1);
        for(auto it : trust){
            ind[it[1]]++;
            ind[it[0]]--;
        }
        for(int i=1;i<=n;i++){
            if(ind[i] == n-1)return i;
        }
        return -1;
    }
};