class Solution:
    def minimumPushes(self, word: str) -> int:
        cur = sorted(Counter(word).values(), reverse = 1)
        k = 0
        ans = 0
        while k < min(8, len(cur)):
            ans += (cur[k])
            k += 1
        while k < min(16, len(cur)):
            ans += (2 * cur[k])
            k += 1
        while k < min(24, len(cur)):
            ans += (3 * cur[k])
            k += 1
        while k < min(26, len(cur)):
            ans += (4 * cur[k])
            k += 1
        return ans