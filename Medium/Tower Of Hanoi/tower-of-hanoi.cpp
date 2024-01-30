//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long dfs(int n,int from,int to, int help){
        if(n == 0)return 0;
        long long ans = dfs(n-1,from,help,to);
        cout<<"move disk "<<n<<" from rod "<<from<<" to rod "<<to<<endl;
        long long res = dfs(n-1,help,to,from);
        return ans + res + 1;;
    }
    long long toh(int N, int from, int to, int aux) {
        return dfs(N,from,to,aux);
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends