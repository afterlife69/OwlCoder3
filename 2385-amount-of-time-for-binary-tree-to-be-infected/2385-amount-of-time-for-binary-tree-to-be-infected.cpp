/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    pair<int,bool> dfs(TreeNode*rt, int x){
        if(!rt)return {0,0};
        if(rt->val == x){
            auto [h1,v1] = dfs(rt->left,x);
            auto [h2,v2] = dfs(rt->right,x);
            ans = max({ans,h1,h2});
            return {1,1};
        }
        auto [h1,v1] = dfs(rt->left,x);
        auto [h2,v2] = dfs(rt->right,x);
        if(v1 || v2){
            int y = h1 + h2;
            ans = max(ans,y);
            if(v1)return {h1+1,1};
            else return {h2+1,1};
        }
        return {max(h1,h2)+1,0};
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return ans;
    }
};