class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        mp = Counter(nums)
        nums.sort(key = lambda x : (mp[x],-x))
        return nums
    