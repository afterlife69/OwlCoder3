//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dfs(int i,int n,int m){
        if(n == 0)return 1;
        if(i > m)return 0;
        int ans = 0;
        for(int j=i;j<=(m/n);j++){
            ans += dfs(2*j,n-1,m);
        }
        return ans;
    }
    int numberSequence(int m, int n){
        return dfs(1,n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends