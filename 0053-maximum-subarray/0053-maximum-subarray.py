class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxi = float('-infinity')
        c = 0
        
        for i in nums:
            c += i
            maxi = max(maxi, c)
            if c < 0:
                c = 0
        return maxi