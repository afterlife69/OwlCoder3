//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int dp[21][21][21];
    int dfs(int i,int j,int k,string &A,string &B,string &C){
        if(i == A.size() || j == B.size() || k == C.size())return 0;
        if(A[i] == B[j] && A[i] == C[k])return 1 + dfs(i+1,j+1,k+1,A,B,C);
        if(dp[i][j][k] != -1)return dp[i][j][k];
        int l = dfs(i+1,j,k,A,B,C);
        int r  = dfs(i,j+1,k,A,B,C);
        int mid = dfs(i,j,k+1,A,B,C);
        return dp[i][j][k] = max({l,r,mid});
    }
    int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,0,A,B,C);
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends