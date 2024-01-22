class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        m=min(set(range(1,len(nums)+1)).difference(set(nums)))
        a=Counter(nums)
        a=[k for k,v in a.items() if v==2][0]
        return [a,m]