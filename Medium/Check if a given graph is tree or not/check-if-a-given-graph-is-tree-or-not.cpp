//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    unordered_map<int,int>par;
    int findd(int x){
        if(par[x] == x)return x;
        return par[x] = findd(par[x]);
    }
    void unionn(int u,int v){
        u = findd(u);
        v = findd(v);
        par[u] = v;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        if(m != n-1)return 0;
        for(int i=0;i<n;i++)par[i] = i;
        for(auto it: adj){
            int u = it[0],v = it[1];
            if(findd(u) == findd(v))return 0;
            unionn(u,v);
        }
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends