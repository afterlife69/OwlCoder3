//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    bool pos(int m, int arr[], int dep[], int n){
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top() < arr[i])pq.pop();
            pq.push(dep[i]);
            if(pq.size() > m)return 0;
        }
        return 1;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep,dep+n);
    	int l = 1, r = n, ans = -1;
    	while(l <= r){
    	    int m = (l + r) /2;
    	    if(pos(m, arr, dep, n)){
    	        ans = m;
    	        r = m - 1;
    	    }
    	    else l = m + 1;
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends