class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0] * (n + 1)
        k = 1
        for i in range(1, n + 1):
            if 2 * k == i:
                k = i
            ans[i] = ans[i - k] + 1
        return ans