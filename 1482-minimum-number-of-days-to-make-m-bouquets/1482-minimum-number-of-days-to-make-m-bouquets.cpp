class Solution {
public:
    bool pos(int dist, int m, int K, vector<int>&v){
        int have = 0, k = K;
        for(int i=0;i<v.size();i++){
            if(k == 0){
                have++;
                k = K;
            }
            if(v[i] <= dist)k--;
            else k = K;
        }
        if(k == 0)have++;
        return have >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int>v(bloomDay.begin(), bloomDay.end());
        sort(begin(v), end(v));
        int low = 0, high = bloomDay.size() - 1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(pos(v[mid], m, k, bloomDay)){
                ans = v[mid];
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};