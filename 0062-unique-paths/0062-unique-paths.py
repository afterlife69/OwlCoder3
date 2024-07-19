class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        l=[[-1 for i in range(102)]for j in range(102)]
        def fun(i,j):
            if i>=m or j>=n:
                return 0
            if i==m-1 and j==n-1:
                return 1
            if l[i][j]!=-1:
                return l[i][j]
            l[i][j]=fun(i+1,j)+fun(i,j+1)
            return l[i][j]
        return fun(0,0)
            