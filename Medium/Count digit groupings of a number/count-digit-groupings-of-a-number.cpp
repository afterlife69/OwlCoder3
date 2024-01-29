//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[101][1001];
	int dfs(int i,int prev, string & s){
	    if(i == s.size())return 1;
	    if(dp[i][prev] != -1)return dp[i][prev];
	    int cur = 0;
	    int ans = 0;
	    for(int j=i;j<s.size();j++){
	        cur += (s[j]-'0');
	        if(cur >= prev)ans += dfs(j+1,cur,s);
	    }
	    return dp[i][prev] = ans;
	}
	int TotalCount(string str){
	    memset(dp,-1,sizeof(dp));
	    int x = dfs(0,0,str);
	    return x;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends