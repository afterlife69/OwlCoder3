//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    unordered_map<char,vector<char>>adjacencyList;
    unordered_map<char,int>inDegree;
    void insertIntoAdjacencyList(string s,string t){
        for(int i=0;i<min(s.size(),t.size());i++){
            if(s[i] != t[i]){
                adjacencyList[s[i]].push_back(t[i]);
                if(!inDegree[s[i]])inDegree[s[i]] = 0;
                inDegree[t[i]]++;
                break;
            }
        }
    }
    string findOrder(string dict[], int N, int K) {
        for(int i=0;i<N-1;i++){
            insertIntoAdjacencyList(dict[i],dict[i+1]);
        }
        queue<char>q;
        for(auto it : inDegree){
            if(it.second == 0)q.push(it.first);
        }
        string ans;
        while(!q.empty()){
            char node = q.front();
            ans += node;
            q.pop();
            for(auto it : adjacencyList[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)q.push(it);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends