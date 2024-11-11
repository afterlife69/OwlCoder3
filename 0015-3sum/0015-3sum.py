class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n =  len(nums)
        ans = set()
        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j, k = i + 1, n - 1
            rem = 0 - nums[i]
            while(j < k):
                if nums[j] + nums[k] == rem:
                    ans.add((nums[i],nums[j],nums[k]))
                    j += 1
                    k = n - 1
                    continue
                elif nums[j] + nums[k] > rem:
                    k -= 1
                else:
                    j += 1
        return list(ans)
        