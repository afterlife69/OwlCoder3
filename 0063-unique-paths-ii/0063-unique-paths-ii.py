class Solution:
    def uniquePathsWithObstacles(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        dp=[[0]*(n+1) for i in range(m+1)]
        dp[m-1][n-1]=1
        if grid[m-1][n-1]==1:
            return 0
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i==m-1 and j==n-1:
                    continue
                if grid[i][j]==1:
                    continue
                left=dp[i+1][j] if i+1<m else 0
                right=dp[i][j+1] if j+1<n else 0
                dp[i][j]=left+right
        return dp[0][0]
        
        