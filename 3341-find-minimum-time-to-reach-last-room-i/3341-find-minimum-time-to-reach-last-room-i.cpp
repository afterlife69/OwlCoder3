class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>>v(n, vector<int>(m, 1e9 + 1000));
        v[0][0] = 0;
        queue<vector<int>>pq;
        vector<int> dx = {0, 0, -1, 1}, dy = {1, -1, 0, 0};
        pq.push({0, 0, 0});
        while(!pq.empty()){
            int wt = pq.front()[0];
            int r = pq.front()[1];
            int c = pq.front()[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int x = dx[i] + r, y = dy[i] + c;
                if(x >= 0 and x < n and y >= 0 and y < m){
                    if(wt >= moveTime[x][y]){
                        if(v[x][y] > wt + 1){
                            v[x][y] = wt + 1;
                            pq.push({wt + 1, x, y});
                        }
                    }
                    else{
                        if(v[x][y] > wt + abs(wt - moveTime[x][y]) + 1){
                            v[x][y] = wt + abs(wt - moveTime[x][y]) + 1;
                            pq.push({v[x][y], x, y});
                        }
                    }
                }
                
            }
        }
        return v[n-1][m-1];
    }
};