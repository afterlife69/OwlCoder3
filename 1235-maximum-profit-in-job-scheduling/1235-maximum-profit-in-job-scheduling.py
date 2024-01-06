class Solution:
    def jobScheduling(self, st: List[int], et: List[int], pr: List[int]) -> int:
        nums = [(st[i],et[i],pr[i]) for i in range(len(st))]
        nums.sort(key = lambda x: (x[0],x[1]))
        dp = [-1]*(len(nums)+1)
        def dfs(i, prev):
            if i == len(nums):
                return 0
            if dp[i] != -1:
                return dp[i]
            l,r = i+1,len(nums)-1
            idx = len(nums)
            while l<=r:
                m = (l+r)//2
                if nums[m][0]>=nums[i][1]:
                    r = m-1
                    idx = m
                else:
                    l = m+1
            ans = dfs(i+1,prev) # np
            if nums[i][0] >= prev:
                ans = max(ans,dfs(idx,nums[i][1]) + nums[i][2])
            dp[i] = ans
            return ans
        return dfs(0,0)
        
        