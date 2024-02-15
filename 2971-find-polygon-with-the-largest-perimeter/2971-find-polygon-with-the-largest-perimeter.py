class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        c = 0
        ans = 0
        for i in nums:
            if c > i:
                ans = c + i
            c+=i
        return ans if ans else -1