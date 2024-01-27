//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Trie{
    public:
        Trie * links[52] = {nullptr};
        bool end;
        Trie(){
            this->end = 0;
        }
};
class Solution {
private:
    Trie* root = new Trie();
public:
    void ins(string & w){
        Trie* t = root;
        for(auto it : w){
            if(isupper(it)){
                if(!t->links[it-'A'+26])t->links[it-'A'+26] = new Trie();
                t = t->links[it - 'A' +  26];
            }
            else{
                if(!t->links[it - 'a'])t->links[it - 'a'] = new Trie();
                t = t->links[it - 'a'];
            }
        }
        t->end = 1;
    }
    set<string>ans;
    bool dfs(int i, int j, vector<vector<char>>&v,Trie* temp,string cur){
        if(i < 0 || j < 0 || j == v[0].size() || i == v.size() || v[i][j] == '-')
            return 0;
        if(isupper(v[i][j])){
            temp = temp->links[v[i][j] - 'A' + 26];
            if(!temp)return 0;
        }
        else{
            temp = temp->links[v[i][j] - 'a'];
            if(!temp)return 0;
        }
        if(temp -> end){
            ans.insert(cur + v[i][j]);
        }
        char t = v[i][j];
        v[i][j] = '-';
        cur += t;
        bool a1 = dfs(i+1,j,v,temp,cur);
        bool a2 = dfs(i+1,j+1,v,temp,cur);
        bool a3 = dfs(i+1,j-1,v,temp,cur);
        bool a4 = dfs(i-1,j+1,v,temp,cur);
        bool a5 = dfs(i-1,j-1,v,temp,cur);
        bool a6 = dfs(i-1,j,v,temp,cur);
        bool a7 = dfs(i,j+1,v,temp,cur);
        bool a8 = dfs(i,j-1,v,temp,cur);
        v[i][j] = t;
        return (a1 || a2 || a3 || a4 || a5 || a6 || a7 || a8);
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    for(auto it : dictionary)ins(it);
	    int n = board.size(), m = board[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            string cur;
	            if(board[i][j] <= 90){
	                if(root->links[board[i][j] - 'A' + 26]){
	                    dfs(i,j,board,root,cur);
	                }
	            }
	            else{
	                if(root->links[board[i][j]-'a']){
	                    dfs(i,j,board,root,cur);
	                }
	            }
	        }
	    }
	    return vector<string>(ans.begin(),ans.end());
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends