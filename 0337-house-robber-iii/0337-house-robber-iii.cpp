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
    unordered_map<TreeNode*,int>dp;
    int dfs(TreeNode* rt){
        if(!rt)return 0;
        if(dp.count(rt))return dp[rt];
        int np = dfs(rt->left)+dfs(rt->right);
        int p = 0;
        if(rt->left)p+=dfs(rt->left->left)+dfs(rt->left->right);
        if(rt->right)p+=dfs(rt->right->left)+dfs(rt->right->right);
        return dp[rt] = max(p + rt->val, np);
    }
    int rob(TreeNode* root) {
        // memset(dp,-1,sizeof(dp));
        return dfs(root);
    }
};