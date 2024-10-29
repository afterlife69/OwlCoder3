class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        
        dp = [[-1] * (27) for i in range(t+1)]
        def dfs(cur, rem):
            if dp[rem][cur] != -1:
                return dp[rem][cur]
            if (cur + rem) > 26:
                dp[rem][cur] = dfs(1, rem - abs(cur - 27)) + dfs(2, rem - abs(cur - 27))
                return dp[rem][cur]
            else:
                return 1
                
        
        ans = 0
        mod = int((10 ** 9) + 7)
        for i in s:
            ans += dfs(ord(i) - 96, t)
            ans %= mod
        return ans