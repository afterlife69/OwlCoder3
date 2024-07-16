# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.LCA = None
        self.u = ""
        self.v = ""

    def findLCA(self, root: Optional[TreeNode], start: int, end: int) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1 if root.val == start or root.val == end else 0
        l = self.findLCA(root.left, start, end)
        r = self.findLCA(root.right, start, end)
        if l and r:
            self.LCA = root
            return 0
        elif (l or r) and (root.val == start or root.val == end):
            self.LCA = root
            return 0
        return l or r or (root.val == start or root.val == end)

    def dfs(self, root: Optional[TreeNode], findVal: int, x: bool) -> int:
        if not root:
            return 0
        if root.val == findVal:
            return 1
        left = self.dfs(root.left, findVal, x)
        rig = self.dfs(root.right, findVal, x)
        if left:
            if not x:
                self.u += 'U'
            else:
                self.v += 'L'
            return 1
        elif rig:
            if not x:
                self.u += 'U'
            else:
                self.v += 'R'
            return 1
        return 0

    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        self.findLCA(root, startValue, destValue)
        self.dfs(self.LCA, startValue, False)
        self.dfs(self.LCA, destValue, True)
        return self.u + self.v[::-1]
        