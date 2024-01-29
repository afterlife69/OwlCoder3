//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int dp[100001];
    int dfs(int i, int n,int arr[]){
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        return dp[i] = max(arr[i] + dfs(i+2,n,arr),dfs(i+1,n,arr));
    }
    int FindMaxSum(int arr[], int n)
    {
        memset(dp,-1,sizeof(dp));
        return dfs(0,n,arr);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends