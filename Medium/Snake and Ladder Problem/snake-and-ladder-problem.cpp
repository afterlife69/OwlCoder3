//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        unordered_map<int,int>mp;
        for(int i=0;i<2*N-1;i+=2){
            mp[arr[i]] = arr[i+1];
        }
        queue<int>q;
        q.push(1);
        vector<int>vis(31);
        vis[1] = 1;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();
                if(node == 30)return lvl;
                for(int i=1;i<=6;i++){
                    int next = node+i;
                    if(mp[next])next = mp[next];
                    if(!vis[next] && next <= 30){
                        q.push(next);
                        vis[next] = 1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends