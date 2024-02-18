#define pii pair<long long,long long>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        sort(meetings.begin(),meetings.end());
        vector<int>ans(n);
        int mx = 0, m = meetings.size();
        priority_queue<int,vector<int>,greater<int>>rooms;
        for(int i=0;i<n;i++){
            rooms.push(i);
        }
        for(auto it : meetings){
            while(!pq.empty() && pq.top().first <= it[0]){
                rooms.push(pq.top().second);
                pq.pop();
            }
            if(rooms.empty()){
                long long cur = pq.top().first,rm = pq.top().second;
                pq.pop();
                ans[rm]++;
                pq.push({it[1] - it[0] + cur,rm});
                mx = max(mx,ans[rm]);
                continue;
            }
            int cur = rooms.top();
            rooms.pop();
            ans[cur]++;
            mx = max(mx,ans[cur]);
            pq.push({it[1],cur});
        }
        for(int i=0;i<n;i++){
            if(ans[i] == mx)return i;
        }
        return 0;
    }
};