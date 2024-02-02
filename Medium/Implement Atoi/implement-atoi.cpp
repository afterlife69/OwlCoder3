//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int ans = 0;
        int j = 1;
        for(int i=s.size() - 1; i>=0; i--){
            if(i == 0 && s[i] == '-'){
                ans *= -1;
                break;
            }
            if(s[i] >= 48 && s[i] <= 57){
                ans += (j * (s[i]-'0'));
                j*=10;
            }
            else return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends