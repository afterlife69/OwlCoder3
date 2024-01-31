class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<int>st;
        vector<int>ans;
        for(int i=v.size()-1;i>=0;i--){
            int c = 1;
            while(!st.empty() && v[st.top()] <= v[i]){
                st.pop();
            }
            if(st.empty()) c = 0;
            ans.push_back(c == 0 ? 0  : st.top() - i);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};