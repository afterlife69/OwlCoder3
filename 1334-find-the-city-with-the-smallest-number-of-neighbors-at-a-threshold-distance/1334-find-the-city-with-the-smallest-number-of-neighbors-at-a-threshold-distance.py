class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dp = [[1e9] * n for i in range(n)]
        for u,v,w in edges:
            dp[u][v] = w
            dp[v][u] = w
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dp[i][j] > dp[i][k] + dp[k][j] and dp[i][k] != 1e9 and dp[k][j] != 1e9:
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
        ans = 1e9
        ret = -1
        for i in range(n):
            cur = 0
            for j in range(n):
                if dp[i][j] <= distanceThreshold and i != j:
                    cur += 1
            if cur <= ans:
                ans = cur
                ret = i
        return ret
        