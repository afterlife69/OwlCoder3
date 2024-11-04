class Solution:
    def isBalanced(self, num: str) -> bool:
        ans = 0
        for i in range(len(num)):
            if i % 2 == 0:
                ans += int(num[i])
            else:
                ans -= int(num[i])
        return ans == 0