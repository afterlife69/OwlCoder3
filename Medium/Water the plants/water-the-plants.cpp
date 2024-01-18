//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    int min_sprinklers(int arr[], int n)
    {
        // 2, 3, 4, -1, 2, 0, 0, -1, 0
        // 0  1  2   3  4  5  6   7  8
        // [0,6][2,6][5,5][6,6][8,8]
        // [0,6][7,7]
        // 0 1 2  3  4 5  6 7  8
        // 3 5 0 -1 -1 4 -1 5 -1
        // [0,3][0,6][2,2][1,8][2,8]
        // [0,6][0,3][1,8
        vector<pair<int,int>>v,cur;
        for(int i=0;i<n;i++){
            if(arr[i] != -1){
                int l = i - arr[i] < 0 ? 0 : i - arr[i];
                int r = i + arr[i] >= n ? n-1 : i + arr[i];
                v.push_back({l,r});
            }
            
        }
        sort(v.begin(),v.end(),comp);
        for(auto it:v){
            if(cur.empty())cur.push_back(it);
            else{
                int l = cur.back().first;
                int r = cur.back().second;
                if(it.second > r)cur.push_back(it);
            }
        }
        // for(auto it : cur){
        //     cout<<it.first<<" "<<it.second<<endl;
        // } 
        int ans = 0;
        if(cur[0].first != 0 || cur.back().second != n-1)return -1;
        int i = 0;
        while(i < cur.size()){
            int pre = cur[i].second;
            // cout<<cur[i].first<<" "<<cur[i].second<<endl;
            int j = i+1;
            bool f = 0;
            ans++;
            while(j < cur.size()){
                if(cur[j].first > pre+1){
                    if(!f)return -1;
                    j--;
                    break;
                }
                f = 1;
                if(j == cur.size()-1){
                    if(cur[i].second >= cur[j].first){
                        // ans++;
                        break;
                    }
                    break;
                }
                j++;
            }
            i = j;
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
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends