# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        mp = defaultdict(int)
        cur = set()
        for u,v,left in descriptions:
            if u not in mp:
                mp[u] = TreeNode(u)
            if v not in mp:
                mp[v] = TreeNode(v)
            if left:
                mp[u].left = mp[v]
            else:
                mp[u].right = mp[v]
            cur.add(mp[v])
        for i in mp:
            if mp[i] not in cur:
                return mp[i]
        return None