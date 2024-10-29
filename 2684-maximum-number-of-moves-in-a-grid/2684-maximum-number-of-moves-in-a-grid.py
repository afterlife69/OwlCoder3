class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n, m = len(grid) , len(grid[0])
        dp = [[-1e9] * m for i in range(n)]
        for i in range(n):
            dp[i][0] = 0
        ans = 0
        for i in range(1, m):
            for j in range(n):
                if grid[j][i-1] < grid[j][i]:
                    dp[j][i] = 1 + dp[j][i-1]
                if (j - 1) >= 0 and grid[j-1][i-1] < grid[j][i]:
                    dp[j][i] = max(dp[j][i], 1 + dp[j-1][i-1])
                if (j + 1) < n and grid[j+1][i-1] < grid[j][i]:
                    dp[j][i] = max(dp[j][i], 1 + dp[j+1][i-1])
                ans = max(ans, dp[j][i])
        return ans
        
        
                    