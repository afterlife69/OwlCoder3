class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0] * n
        dp2 = [0] * n
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if i == (m - 1) and j == (n - 1):
                    dp[j] = 1
                    continue
                left = dp2[j] if (i + 1) < m else 0
                right = dp[j+1] if (j + 1) < n else 0
                dp[j]= left + right
            dp2 = dp
        return dp[0]
            