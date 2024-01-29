//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int dp[101][50001];
    bool dfs(int i,int cur,int tar,int arr[],int n,vector<vector<int>>&dp){
        if(i == n)return dp[i][cur] = cur == tar;
        if(cur == tar) return dp[i][cur] = 1;
        if(cur > tar)return dp[i][cur] = 0;
        if(dp[i][cur] != -1)return dp[i][cur];
        return dp[i][cur] = dfs(i+1,cur+arr[i],tar-arr[i],arr,n,dp) || dfs(i+1,cur,tar,arr,n,dp);
    }
    int equalPartition(int N, int arr[])
    {
        // memset(dp,-1,sizeof(dp));
        int cur = 0;
        for(int i=0;i<N;i++)cur += arr[i];
        vector<vector<int>>dp(N+1,vector<int>(cur+1,-1));
        return dfs(0,0,cur,arr,N,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends