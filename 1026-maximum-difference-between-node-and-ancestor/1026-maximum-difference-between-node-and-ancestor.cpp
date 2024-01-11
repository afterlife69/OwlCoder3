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
    pair<int,int> dfs(TreeNode* rt){
        if(!rt)return {-1,-1};
        if(!rt->left && !rt->right)return {rt->val,rt->val};
        auto [l1,r1] = dfs(rt->left);
        auto [l2,r2] = dfs(rt->right);
        int mn = 1e9,mx = 0;
        if(l1 != -1){
            mn = l1;
            mx = l1;
        }
        if(l2 != -1){
            mn = min(mn,l2);
            mx = max(mx,l2);
        }
        if(r1 != -1){
            mn = min(mn,r1);
            mx = max(mx,r1);
        }
        if(r2 != -1){
            mn = min(mn,r2);
            mx = max(mx,r2);
        }
        ans = max({ans,abs(rt->val-mn),abs(rt->val-mx)});
        return {min(mn,rt->val),max(mx,rt->val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};