//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>ans;
    void dfs(int o, int c, string cur,int n){
        if(o == n && c== n){
            ans.push_back(cur);
            return ;
        }
        if(o < n)dfs(o+1,c,cur+'(',n);
        if(o > c)dfs(o,c+1,cur+')',n);   
    }
    vector<string> AllParenthesis(int n) 
    {
        string x;
        dfs(0,0,x,n);
        return ans;
        // Your code goes here 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends