//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10001];
    int dfs(int n,unordered_set<int>&x){
        if(n == 0)return 1;
        if(n < 0)return -1e9;
        if(dp[n] != -1)return dp[n];
        int ans = -1e9;
        for(auto it : x){
            if(n % it == 0)ans = max(ans, n / it);
            else ans = max(ans, dfs(n-it,x) + 1);
        }
        return dp[n] = ans;
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
        unordered_set<int>s;
        s.insert(x);
        s.insert(y);
        s.insert(z);
        int ans = dfs(n,s);
        return ans < 0 ? 0 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends