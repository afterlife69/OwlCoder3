//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Trie{
    public:
        Trie* L[26] = {nullptr};
        int cnt;
        Trie(){
            cnt = 0;
        }
};
class Solution {
    Trie* root = new Trie();
    public:
    void ins(string &w){
        Trie* t = root;
        for(auto a : w){
            if(!t->L[a-'a'])t->L[a-'a']=new Trie();
            t->cnt++;
            t = t->L[a-'a'];
        }
        t->cnt++;
    }
    string longestCommonPrefix(vector<string> arr) {
        int cur = 1e9;
        for(auto it : arr){cur = min(cur,int(it.size())); ins(it);}
        string ans;
        for(int i=0;i<cur;i++){
            if(root->cnt != arr.size())break;
            for(int j=0;j<26;j++){
                if(root->L[j]){
                    root = root->L[j];
                    if(root->cnt == arr.size())
                    ans += char(j + 'a');
                    break;
                }
            }
        }
        return ans.empty() ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends