class Solution {
public:
    unordered_set<int>ans;
    
    void dfs(int i,int prev,int k){
        if(i == 0){
            ans.insert(prev);
            return;
        }
        if((prev % 10) - k >= 0){
            int cur = (prev %10) - k;
            dfs(i-1,(prev*10 + cur) ,k);
        }
        if((prev % 10) + k <= 9){
            int cur = (prev %10) + k;
            dfs(i-1,(prev *10 + cur),k);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            dfs(n-1,i,k);
        }
        return vector<int>(ans.begin(),ans.end());
    }
};