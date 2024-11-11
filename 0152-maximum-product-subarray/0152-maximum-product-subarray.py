class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        maxi, mini, res = 1, 1, float('-infinity')
        for i in nums:
            t = maxi * i
            maxi = max(i, t, mini * i)
            mini = min(i, t, mini * i)
            res = max(res, maxi)
        return res