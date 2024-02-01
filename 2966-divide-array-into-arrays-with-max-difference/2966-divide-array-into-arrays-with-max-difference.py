class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        ans = []
        for i in range(1,len(nums),3):
            if abs(nums[i-1] - nums[i]) <= k and abs(nums[i+1]-nums[i]) <=k and abs(nums[i-1]-nums[i+1]) <= k:
                ans.append(nums[i-1 : i+2])
            else:
                return []
        return ans