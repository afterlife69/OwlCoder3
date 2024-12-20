class Solution:
    def findMin(self, nums: List[int]) -> int:
        res = nums[0]
        l, r = 0, len(nums) - 1
        while(l <= r):
            m = (l + r) >> 1
            if nums[l] <= nums[m] and nums[m] <= nums[r]:
                return nums[l]
            elif nums[l] <= nums[m]:
                l = m + 1
            else:
                r = m
        