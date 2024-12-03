class Solution:
    def minDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 4:
            return 0
        nums.sort()
        ans = float('inf')
        a = nums[n-4] - nums[0]
        b = nums[n-3] - nums[1]
        c = nums[n-2] - nums[2]
        d = nums[n-1] - nums[3]
        return min(a,b,c,d)