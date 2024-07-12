class Solution:
    def canJump(self, nums: List[int]) -> bool:
        run = 0
        for i in range(len(nums)):
            if i == len(nums) - 1:
                return 1
            if nums[i] > run:
                run = nums[i]
            run -= 1
            if run < 0:
                return 0
        return 1