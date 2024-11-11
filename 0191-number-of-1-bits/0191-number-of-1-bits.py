class Solution:
    def hammingWeight(self, n: int) -> int:
        c = 0
        while n:
            a = n
            c += a & 1
            n = n>>1
        return c
        