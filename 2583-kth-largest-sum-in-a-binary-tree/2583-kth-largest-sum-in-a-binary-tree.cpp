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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        queue<TreeNode*>q;
        // k--;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            long long cur = 0;
            while(sz--){
                auto n = q.front();
                cur += n->val;
                q.pop();
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            pq.push(cur);
        }
        if(pq.size() < k)return -1;
        while(--k)pq.pop();
        return pq.top();
    }
};