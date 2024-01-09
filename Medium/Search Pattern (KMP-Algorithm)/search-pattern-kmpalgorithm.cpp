//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int n = pat.size(), m = txt.size();
            vector<int>lps(txt.size());
            int i = 0, j = 1;
            while(j < n){
                if(pat[i] == pat[j]){
                    lps[j] = i+1;
                    i++;
                    j++;
                }
                else{
                    if(i == 0){
                        lps[j] = 0;
                        j++;
                    }
                    else i = lps[i-1];
                }
            }
            i = 0, j = 0;
            vector<int>ans;
            while(i < m){
                if(txt[i] == pat[j]){
                    i++;
                    j++;
                }
                else{
                    if(j == 0)i++;
                    else j = lps[j -1];
                }
                if(j == n){
                    ans.push_back(i - n + 1);
                    j = lps[j-1];
                }
            }
            return ans;
        }
     
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends