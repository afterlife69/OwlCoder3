class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>pos,neg;
        for(auto it : nums){
            if(it < 0)neg.push(it);
            else pos.push(it);
        }
        vector<int>ans;
        bool f = 0;
        while(!pos.empty() && !neg.empty()){
            if(!f){
                ans.push_back(pos.front());
                pos.pop();
            }
            else{
                ans.push_back(neg.front());
                neg.pop();
            }
            f = !f;
        }
        while(!pos.empty()){
            ans.push_back(pos.front());
            pos.pop();
        }
        while(!neg.empty()){
            ans.push_back(neg.front());
            neg.pop();
        }
        return ans;
    }
};