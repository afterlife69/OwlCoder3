class Solution:
    def numWays(self, words: List[str], s: str) -> int:
        wrd = [defaultdict(int) for i in range(len(words[0]))]
        for i in words:
            for j in range(len(i)):
                wrd[j][i[j]] += 1
        n = len(s)
        dp = [[-1]*(len(wrd)+1) for j in range(n+1)]
        mod = int(10**9) + 7
        def dfs(i,j):
            if i == n:
                return 1
            if j == len(wrd):
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            ans = 0
            if s[i] in wrd[j]:
                ans += (dfs(i+1,j+1) * wrd[j][s[i]])%mod
            dp[i][j] = (ans + dfs(i,j+1))%mod
            return dp[i][j]
        return dfs(0,0)%mod