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
    int dfs(TreeNode* rt,int a){
        if(!rt)return 0;
        a ^= (1 << rt->val);
        if(!rt->left && !rt->right){
            int cnt = 0;
            for(int i = 9; i>=0; i--)cnt += (a >> i)&1;
            return cnt <= 1;
        }
        int left = dfs(rt->left,a);
        int rig = dfs(rt->right,a);
        return left + rig;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root,0);
    }
};