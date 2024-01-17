//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  set<vector<int>>res;
    void dfs(vector<int>&ar,vector<bool>&vis,int n,vector<int>&v){
        if(v.size() == n){
            res.insert(v);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i] = 1;
                v.push_back(ar[i]);
                dfs(ar,vis,n,v);
                v.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<bool>vis(n);
        vector<int>cur;
        dfs(arr,vis,n,cur);
        vector<vector<int>>v(res.begin(),res.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends