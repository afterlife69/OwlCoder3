class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1)return stoi(tokens[0]);
        stack<int>st;
        int ans = 0;
        for(auto it : tokens){
            if(it[0] >=48 && it[0]<=57 || it.size() > 1)
            st.push(stoi(it));
            else{
                if(it == "+"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans = (a + b);
                }
                else if(it == "-"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans = (b - a);
                }
                else if(it == "*"){
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans = (a * b);
                }
                else{
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    ans = (b / a);
                }
                st.push(ans);
            }
        }
        return ans;
    }
};