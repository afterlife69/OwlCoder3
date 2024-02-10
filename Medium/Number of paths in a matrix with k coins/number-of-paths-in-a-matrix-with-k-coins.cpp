//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long dp[100][100][100];
    long long dfs(int r,int c,int k,vector<vector<int>>&v,int n){
        if(r == n-1 && c == n-1)return k == v[r][c];
        if(r == n || c == n)return 0;
        if(dp[r][c][k] != -1)return dp[r][c][k];
        if(k <= 0)return 0;
        long long left = dfs(r+1,c,k-v[r][c],v,n);
        long long rigt = dfs(r,c+1,k-v[r][c],v,n);
        return dp[r][c][k] = left + rigt;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,k,arr,n);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends