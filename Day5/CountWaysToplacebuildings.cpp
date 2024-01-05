//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N)
	{
	    const int mod = 1e9 + 7;
	    if(N == 1)return 4;
	    int a = 1, b=2, c= 0;
	    for(int i=2;i<=N;i++){
	        c = (a + b)%mod;
	        a = b;
	        b = c;
	    }
	    return (1LL*c*c)%mod;
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends