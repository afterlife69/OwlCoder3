class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int>dp(n);
        stack<int>st;
        const int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] <= arr[st.top()])st.pop();
            if(st.empty())dp[i] += arr[i]*(i+1);
            else dp[i] += dp[st.top()] + arr[i] * (i - st.top());
            ans += dp[i];
            ans %= mod;
            st.push(i);
        }
        return ans;
    }
};