class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n);
        const int mod = 1e9 + 7;
        dp.back() = arr.back();
        for(int i=n-2;i>=0;i--){
            int cur = arr[i];
            for(int j=i+1;j<n;j++){
                if(arr[j] < arr[i]){
                    cur += dp[j];
                    cur%=mod;
                    break;
                }
                cur += (arr[i]);
                cur = cur%mod;
            }
            dp[i] = cur%mod;
        }
        int ans = 0;
        for(auto it: dp){
            ans += it;
            ans %= mod;
        }
        return ans;
    }
};