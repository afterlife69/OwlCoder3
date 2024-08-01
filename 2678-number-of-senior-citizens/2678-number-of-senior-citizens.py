class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans = 0
        for i in details:
            ans += (int(i[-4]+i[-3]) > 60)
        return ans