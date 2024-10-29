class Solution:
    def maxMoves(self, grid: List[List[int]]) -> int:
        n, m = len(grid) , len(grid[0])
        
        @cache
        def dfs(i, j):
            if j == m:
                return 0
            ans = 0
            if (j + 1) < m:
                if (i - 1) >= 0 and grid[i-1][j+1] > grid[i][j]:
                    ans = max(ans, dfs(i-1, j+1) + 1)
                if grid[i][j+1] > grid[i][j]:
                    ans = max(ans, dfs(i, j+1) + 1)
                if (i + 1) < n and grid[i+1][j+1] > grid[i][j]:
                    ans = max(ans, dfs(i+1,j+1) + 1)
            return ans
            
        
        ans = 0
        for i in range(n):
            ans = max(ans, dfs(i, 0))
        return ans
        
                    