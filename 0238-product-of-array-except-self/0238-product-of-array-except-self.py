class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1] * n
        k, l = 1, 1
        for i in range(n):
            ans[i] *= k
            ans[n - i - 1] *= l
            k *= nums[i]
            l *= nums[n - i - 1]
        return ans
            