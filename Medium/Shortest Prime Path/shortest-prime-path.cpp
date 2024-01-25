//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool pr(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n % i == 0)return 0;
        }
        return 1;
    }
    int solve(int num1,int num2)
    {   
        queue<pair<int,int>>q;
        q.push({num1,0});
        unordered_map<int,bool>vis;
        while(!q.empty()){
            int cur = q.front().first;
            int lv = q.front().second;
            q.pop();
            //ones
            if(cur == num2)return lv;
            int t = (cur / 10)*10;
            for(int i=1;i<=9;i+=2){
                if(pr(t + i) && !vis[t + i]){
                    q.push({t+i,lv+1});
                    vis[t + i] = 1;
                }
            }
            //tens;
            t = (cur / 100) * 100;
            int rem = (cur % 10);
            for(int i=0;i<=9;i++){
                int x = t + rem + (i * 10);
                if(pr(x) && !vis[x]){
                    q.push({x,lv+1});
                    vis[x] = 1;
                }
            }
            //hundred
            t = (cur / 1000)*1000;
            rem = (cur % 100);
            for(int i=0;i<=9;i++){
                int x = t + rem + (i * 100);
                if(pr(x) && !vis[x]){
                    q.push({x,lv+1});
                    vis[x] = 1;
                }
            }
            //thousand
            rem = (cur % 1000);
            for(int i=1;i<=9;i++){
                int x = (i * 1000) + rem;
                if(pr(x) && !vis[x]){
                    q.push({x,lv + 1});
                    vis[x] = 1;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends