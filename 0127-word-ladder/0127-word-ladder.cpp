class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool>mp;
        // queue<int>q;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]] = 1;
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string node = q.front().first;
            int lvl = q.front().second;
            if(node == endWord)return lvl;
            q.pop();
            for(int i=0;i<node.size();i++){
                for(int j='a';j<='z';j++){
                    string left = node.substr(0,i);
                    string right = node.substr(i+1,node.size());
                    if(mp[left + char(j) + right]){
                        mp[left + char(j) + right] = 0;
                        q.push({left + char(j) + right,lvl+1});
                    }
                }
            }
        }
        return 0;
    }
};