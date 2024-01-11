//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K){
        string ans;
        stack<char>st,st1;
        for(auto it : S){
            if(st.empty() || st.top() <= it)st.push(it);
            else{
                while(!st.empty() && st.top() > it && K){st.pop(); K--;}
                st.push(it);
            }
        }
        while(!st.empty() && K){st.pop();K--;}
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        while(!st1.empty() && st1.top() == '0')st1.pop();
        while(!st1.empty()){
            ans += st1.top();
            st1.pop();
        }
        return ans.empty()?"0":ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends