class Solution:
    def maxDepth(self, s: str) -> int:
        ans = 0
        st = 0
        for i in s:
            if i == '(':
                st += 1
            elif i == ')':
                st -= 1
            ans = max(ans,st)
        return ans