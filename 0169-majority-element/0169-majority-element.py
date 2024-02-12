class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp = defaultdict(lambda : 0)
        for it in nums:
            mp[it]+=1
            if mp[it] > len(nums)//2:
                return it
        return 69