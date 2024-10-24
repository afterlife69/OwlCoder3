# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(r1, r2):
            if not r1 and not r2:
                return True
            if not r1 or not r2:
                return False
            ans = (dfs(r1.left, r2.left) or dfs(r1.left, r2.right)) and (dfs(r1.right, r2.left) or dfs(r1.right, r2.right))
            return ans and r1.val == r2.val
        return dfs(root1, root2)
        