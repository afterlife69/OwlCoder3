class Solution:
    def countVowelPermutation(self, n: int) -> int:
        
        dp = [[-1]*(6) for i in range(n+1)]
        def dfs(i,c):
            if i == 0:
                return 1
            if dp[i][c] != -1:
                return dp[i][c]
            x = 0
            if c == 1:
                x = dfs(i-1,2)
            elif c == 2:
                x = dfs(i-1,3) + dfs(i-1,1)
            elif c == 3:
                x = dfs(i-1,1) + dfs(i-1,2) + dfs(i-1,4) + dfs(i-1,5)
            elif c == 4:
                x = dfs(i-1,3) + dfs(i-1,5)
            else:
                x = dfs(i-1,1)
            dp[i][c] = x
            return x
        ans = 0
        for i in range(1,6):
            ans += dfs(n-1,i)
        return ans % (10 ** 9 + 7)
        