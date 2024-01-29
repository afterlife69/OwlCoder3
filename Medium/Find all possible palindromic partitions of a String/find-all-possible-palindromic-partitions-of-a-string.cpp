//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<string>>ans;
    bool pal(string &s){
        int i = 0, j = s.size() -1;
        while(i <= j){
            if(s[i] != s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    void dfs(int i,string &c,vector<string>&cur,string S){
        if(i == S.size()){
            string y;
            for(auto it : cur){
                y += it;
                if(!pal(it))return;
            }
            if(y == S)
            ans.push_back(cur);
            return;
        }
        c += S[i];
        string x;
        cur.push_back(c);
        dfs(i+1,x,cur,S);
        cur.pop_back();
        dfs(i+1,c,cur,S);
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<string>x;
        string c;
        dfs(0,c,x,S);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends