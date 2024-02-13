class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto it : words){
            int l = 0, r = it.size()-1;
            bool ok = 1;
            while(l < r){
                if(it[l++] != it[r--]){
                    ok = 0;
                    break;
                }
            }
            if(ok)return it;
        }
        return "";
    }
};