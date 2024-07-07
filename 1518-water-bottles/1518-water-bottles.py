class Solution:
    def numWaterBottles(self, n: int, k: int) -> int:
        ans = n
        e = 0
        while n >= k:
            ans += (n // k)
            n = (n // k) + (n % k)
        return ans
            
            