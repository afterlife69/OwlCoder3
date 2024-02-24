#define vi vector<int>
class Solution {
public:
    vector<int>par;
    int Find(int x){
        return par[x] == x ? x : par[x] = Find(par[x]);
    }
    int winFind(int x){
        if(par[x] == x && x == 0)return 0;
        else if(par[x] == x)return -1;
        int y = winFind(par[x]);
        if(y == -1)par[x] = x;
        else par[x] = 0;
        return y;
    }
    void Union(int u,int v){
        u = Find(u);
        v = Find(v);
        if(u == 0)par[v] = u;
        else par[u] = v;
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) {
        par.resize(n);
        iota(par.begin(),par.end(),0);
        priority_queue<vi,vector<vi>,greater<vi>>pq;
        for(auto it : meet){
            pq.push({it[2],it[0],it[1]});
        }
        Union(0,firstPerson);
        while(!pq.empty()){
            int cur = pq.top()[0];
            stack<vector<int>>st;
            while(!pq.empty()){
                int time = pq.top()[0];
                int u = pq.top()[1];
                int v = pq.top()[2];
                if(cur != time){
                    while(!st.empty()){
                        int time1 = st.top()[0];
                        int u1 = st.top()[1];
                        int v1 = st.top()[2];
                        if(Find(v1) != 0){
                            par[v1] = v1;
                            par[u1] = u1;
                        }
                        st.pop();
                    }
                    break;
                }
                Union(u,v);
                st.push(pq.top());
                pq.pop();
            }
        }
        for(int i=0;i<n;i++)Find(i);
        vector<int>ans;
        for(int i=0;i<par.size();i++)if(par[i] == 0)ans.push_back(i);
        return ans;
    }
};