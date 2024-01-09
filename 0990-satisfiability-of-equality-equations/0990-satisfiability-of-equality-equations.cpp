class Solution {
public:
    unordered_map<char,char>mp;
    char findd(char x){
        if(mp[x] == x)return x;
        return mp[x] = findd(mp[x]);
    }
    void unionn(char u, char v){
        u = findd(u);
        v = findd(v);
        mp[u] = v;
    }
    bool equationsPossible(vector<string>& equations) {
        for(auto it:equations){
            mp[it[0]] = it[0];
            mp[it[3]] = it[3];
        }
        for(auto it:equations){
            if(it[1] == '=')unionn(it[0],it[3]);
        }
        for(auto it: equations){
            if(it[1] == '='){
                if(findd(it[0]) != findd(it[3]))return 0;
            }
            else{
                if(findd(it[0]) == findd(it[3]))return 0;
            }
        }
        return 1;
    }
};