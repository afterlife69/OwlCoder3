//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pos(int dist,int arr[],int k,int n){
        int cur = arr[0],cnt = 1,ans = 0;
        for(int i=1;i<n;i++){
            if((cur + arr[i]) <= dist)cur += arr[i];
            else{
                cnt++;
                cur = arr[i];
            }
            ans = max(ans,cur);
        }
        // if(cur + arr[n-1] >= dist)cnt++;
        if(cnt < k)return -1;
        if(cnt == k) return ans;
        if(cnt > k)return -2;
    }
    // 3
    // 1 2 3 4
    
    int splitArray(int arr[] ,int N, int K) {
        int l=arr[0],r=0 ,ans = 1e9;
        for(int i=0;i<N;i++){
            r+=arr[i];
            l = max(l,arr[i]);
        }
        if(N == K)return l;
        if(K == 1)return r;
        while(l <= r){
            int m = (l+r)/2;
            int x = pos(m,arr,K,N);
            if(x>0){
                ans = min(ans,x);
                r = m - 1;
            }
            else if(x == -2)l = m+1;
            else r = m-1;
        }
        return ans == 1e9 ? l : ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends