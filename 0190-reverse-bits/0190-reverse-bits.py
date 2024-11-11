class Solution:
    def reverseBits(self, n: int) -> int:
        ans = 0
        for i in range(32):
            k = (n >> i) & 1
            ans = ans | (k << (31 - i))
        return ans
        