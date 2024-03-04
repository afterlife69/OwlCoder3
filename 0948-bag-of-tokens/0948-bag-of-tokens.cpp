class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i = 0, j = tokens.size() - 1;
        int scr = 0,ans = 0;
        while(i <= j){
            if(power >= tokens[i]){
                power-=tokens[i];
                scr++;
                i++;
            }
            else if(scr > 0){
                power += tokens[j];
                scr--;
                j--;
            }
            else break;
            ans = max(ans,scr);
        }
        return ans;
    }
};