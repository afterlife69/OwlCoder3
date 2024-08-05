class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        v = []
        for i in range(n):
            cur = 0
            for j in range(i,n):
                cur += nums[j]
                v.append(cur)
        v.sort()
        return sum(v[left-1: right]) % (10 ** 9 + 7)