class Solution {
public:
    // 1 8 16 20
    // 2 4 7 33
    int ans = 0;
    void dfs(vector<int>&v,int l,int m,int r){
        vector<int>cur(r-l+1);
        int k=0, i = l, j = m+1;
        for(int i=l;i<=m;i++){
            int low = m+1;
            int high = r;
            while(low <= high){
                int mid = (low + high) / 2;
                if(v[i] > 2LL*v[mid]) low = mid + 1;
                else high = mid - 1;
            }
            ans += (low - (m+1));
        }
        i = l;
        j = m+1;
        while(i <= m && j <= r){
            if(v[i] <= v[j]){
                cur[k++] = v[i++];
            }
            else{
                cur[k++] = v[j++];
            }
        }
        while(i <= m)cur[k++] = v[i++];
        while(j <= r)cur[k++] = v[j++];
        k = 0;
        for(int i=l;i<=r;i++)v[i] = cur[k++];
    }
    void MS(int l,int r,vector<int>&v){
        if(l >= r)return;
        int m = (l+r)/2;
        MS(l,m,v);
        MS(m+1,r,v);
        dfs(v,l,m,r);
    }
    int reversePairs(vector<int>& nums) {
        MS(0,nums.size() -1, nums);
        // for(auto it: nums)cout<<it<<" ";
        return ans;
    }
};