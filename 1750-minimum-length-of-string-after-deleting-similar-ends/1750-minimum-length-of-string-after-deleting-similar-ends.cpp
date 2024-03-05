class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() -1;
        while(i < j){
            if(s[i] != s[j])break;
            while(i < s.size() -1 && s[i+1] == s[j])i++;
            while(j > i && s[j-1] == s[i])j--;
            i++;
            j--;
        }
        if(i > j)return 0;
        return j - i + 1;
    }
};