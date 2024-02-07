//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[101][101];
    int dfs(int l,int r,int arr[],int N){
        if(l >= r){
            // cout<<"hi\n";
            return 0;
        }
        if(dp[l][r] != -1)return dp[l][r];
        int ans = 1e9;
        for(int i = l; i < r; i++){
            int left = dfs(l,i,arr,N);
            int right = dfs(i+1,r,arr,N);
            // cout<<left + right + (arr[l] * arr[i] * arr[r])<<endl;
            ans = min(ans, left + right + (arr[l-1] * arr[i] * arr[r]));
        }
        return dp[l][r] = ans == 1e9 ? 0 : ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return dfs(1,N-1,arr,N);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends