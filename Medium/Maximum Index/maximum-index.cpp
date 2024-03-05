//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // 34, 8, 10, 3, 2, 80, 30, 33, 1
        // 34  8  8   3  2  2   2    2  2
        // 1  33  33 80 80  80  80  80  80
        // 9 4 8 16 19 2
        // 9 4  4  4  4  2
        
        
        vector<int>pref(n);
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = min(pref[i-1],a[i]);
        }
        
        int res = 0;
        for(int i=n-1;i>=0;i--){
            int l = 0, r = i;
            int ans = i;
            while(l <= r){
                int m = (l + r)/2;
                if(pref[m] <= a[i]){
                    r = m - 1;
                    ans = m;
                }
                else l = m + 1;
            }
            if(ans < i)res = max(res,i - ans);
        }
        return res;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends