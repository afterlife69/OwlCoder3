#define pi pair<int,int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        vector<pi>v;
        for(int i=0;i<profits.size();i++)v.push_back({profits[i],capital[i]});
        sort(begin(v), end(v), [&](const pi &a, const pi &b) -> bool {
            if(a.second == b.second)return a.first > b.first;
            return a.second < b.second;
        });
        for(auto &[a,b] : v){
            if(b <= w){
                pq.push(a);
            }
            else{
                while(!pq.empty() && w < b){
                    if(k == 0)break;
                    w += pq.top();
                    pq.pop();
                    k--;
                }
                if(b <= w)pq.push(a);
                else break;
            }
        }
        while(!pq.empty()){
            if(k == 0)break;
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};