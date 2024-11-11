class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('infinity')]* (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for j in coins:
                if i - j >= 0:
                    dp[i] = min(dp[i], 1 + dp[i - j])
        return dp[amount] if dp[amount] != float('infinity') else -1
        