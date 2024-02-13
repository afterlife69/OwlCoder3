//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<bool>vis(1e5,0);
        queue<int>q;
        q.push(start);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                if(node == end)return ans;
                for(auto it : arr){
                    if(!vis[(node * it) % 100000]){
                        vis[(node * it) % 100000] = 1;
                        q.push((node * it ) % 100000);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends