//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>res;
    void dfs(int r,int c,int n,vector<vector<int>>&v,string cur){
        if(r < 0 || c < 0 || r == n || c == n || v[r][c] == 2 || v[r][c] == 0)return;
        if(r == n-1 && c == n-1){
            res.push_back(cur);
            return ;
        }
        v[r][c] = 2;
        dfs(r+1,c,n,v,cur + "D");
        dfs(r-1,c,n,v,cur + "U");
        dfs(r,c+1,n,v,cur + "R");
        dfs(r,c-1,n,v,cur + "L");
        v[r][c] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        dfs(0,0,n,m,"");
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends