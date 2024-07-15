//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(9 * d < s)return "-1";
        string ans;
        for(int i=0;i<d;i++){
            if((s) >= 10){
                s -= 9;
                ans = '9' + ans;
            }
            else{
                if((d -i) == 1)ans = char(s+48) + ans;
                else{
                    ans = char(s+48-1) + ans;
                    for(int j=i+1;j<d-1;j++)ans = '0' + ans;
                    ans = '1' + ans;
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends