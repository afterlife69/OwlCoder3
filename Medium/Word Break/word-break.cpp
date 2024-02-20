//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Trie{
    public:
        Trie * links[26] = {nullptr};
        bool end;
        Trie(){
            end = 0;
        }
};
class Solution
{
private:
    Trie * root = new Trie();
public:
    bool dfs(int i,string &s,Trie *rt){
        if(i == s.size())return rt->end;
        rt = rt->links[s[i]-'a'];
        if(!rt)return 0;
        if(rt->end && dfs(i+1,s,root))return 1;
        return dfs(i+1,s,rt);
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
        for(auto it : dictionary){
            Trie * t = root;
            for(auto it2 : it){
                if(!t->links[it2-'a'])t->links[it2-'a'] = new Trie();
                t = t->links[it2-'a'];
            }
            t->end = 1;
        }
        return dfs(0,s,root);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends