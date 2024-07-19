class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        dp=[[-1]*(n+1) for i in range(m+1)]
        def fun(i,j):
            if i>=m or j>=n:
                return 0
            
            
            if grid[i][j]==1:
                return 0
            if i==m-1 and j==n-1:
                return 1
            if dp[i][j]!=-1:
                return dp[i][j]
            dp[i][j]=fun(i+1,j)+fun(i,j+1)
            return dp[i][j]
        return fun(0,0)
        