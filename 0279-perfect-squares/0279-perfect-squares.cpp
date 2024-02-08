class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>>q;
        q.push({n,0});
        unordered_set<int>vis;
        while(!q.empty()){
            auto [num,lvl] = q.front();
            q.pop();
            if(num == 0)return lvl;
            for(int i=1;i*i<=num;i++){
                if(vis.find(num - (i*i))==vis.end()){
                    vis.insert(num - (i*i));
                    q.push({num-(i*i),lvl+1});
                }
            }
        }
        return -1;
    }
};