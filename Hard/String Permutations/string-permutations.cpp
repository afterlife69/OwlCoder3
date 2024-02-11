//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string>res;
    void dfs(string &s,string &cur,vector<bool>&vis){
        if(cur.size() == s.size()){
            res.push_back(cur);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                vis[i] = 1;
                cur+=s[i];
                dfs(s,cur,vis);
                vis[i] = 0;
                cur.pop_back();
            }
        }
    }
    vector<string> permutation(string S)
    {
        vector<bool>vis(S.size(),0);
        string sl;
        dfs(S,sl,vis);
        sort(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends