//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Trie{
    public:
        Trie* v0 = nullptr,*v1 = nullptr;
        bool end;
        Trie(){
            this->end = 0;
        }
};
class Solution
{   private:
        Trie* root = new Trie();
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        vector<int>ans;
        for(int i=0;i<M;i++){
            Trie *rt = root;
            for(int j=0;j<N;j++){
                if(matrix[i][j] == 0){
                    if(!rt->v0)rt->v0 = new Trie();
                    rt = rt->v0;
                }
                else{
                    if(!rt->v1)rt->v1 = new Trie();
                    rt = rt->v1;
                }
                if(j == N-1){
                    if(rt->end)ans.push_back(i);
                    else rt->end = 1;
                }
            }
        }
        return ans;
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends