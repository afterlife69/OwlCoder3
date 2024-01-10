# Definition for a binary tree node.
# class TreeNode:
#     def _init_(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        d=defaultdict(list)
       
        def fun(root,d):
            if root==None:
                return
            if root.left!=None:
                d[root.val].append(root.left.val)
                
            if root.right!=None:
                d[root.val].append(root.right.val)
                
            fun(root.left,d)
            fun(root.right,d)
        fun(root,d)
        p=d.copy()
        print(p)
        for i in d.keys():
            a=d[i]
            for j in a:
                if i not in p[j]:
                    p[j].append(i)
        print(p)
        def dfs(rt,p,vis,c):
            for i in p[rt]:
                if vis[rt]!=0:
                    vis[rt]=1
                    dfs(i,p,vis,c+1)
            #vis[rt]=1
                    
        vis=[0]*(1000000+1)
        ans=0
        l=[[start,0]]
        c=0
        vis[start]=1
        while l:
            b=l[0]
            l.pop(0)
            c = max(c,b[1])
            for i in p[b[0]]:
                if not vis[i]:
                    vis[b[0]] = 1
                    l.append([i,b[1]+1])
                
                
        return c