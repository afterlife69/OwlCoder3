class Solution {
public:
    int furthestBuilding(vector<int>& v, int bricks, int ladders) {
        int n = v.size(),i,j;
        priority_queue<int>pq;
        for(i=0;i<n-1;i++){
            if(v[i] < v[i+1]){
                int need = v[i+1]-v[i];
                pq.push(need);
                if(need <= bricks){
                    bricks -= need;
                }
                else{
                    while(ladders && !pq.empty()){
                        bricks += pq.top();
                        pq.pop();
                        ladders--;
                        if(bricks >= need)break;
                    }
                    if(need <= bricks){
                        bricks -= need;
                    }
                    else{
                        if(ladders)ladders--;
                        else break;
                    }
                }
            }
        }
        return i;
    }
};