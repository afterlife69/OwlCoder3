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
    unordered_map<int,int>mp;
    int dfs(TreeNode* rt){
        if(!rt)return 0;
        if(!rt->left && !rt->right){
            mp[rt->val]++;
            int cnt = 0;
            for(auto it: mp)if(it.second % 2)cnt++;
            mp[rt->val]--;
            return cnt <= 1;
        }
        mp[rt->val]++;
        int left = dfs(rt->left);
        int rig = dfs(rt->right);
        mp[rt->val]--;
        return left + rig;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root);
    }
};