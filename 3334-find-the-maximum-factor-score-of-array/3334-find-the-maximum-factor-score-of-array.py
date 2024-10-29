class Solution:
    def maxScore(self, nums: List[int]) -> int:
        gd = reduce(lambda x,y:(gcd(x, y)), nums)
        lm = reduce(lambda x,y:(lcm(x, y)), nums)
        ans = gd * lm
        for i in range(len(nums)):
            lp = reduce(lambda x,y: (gcd(x, y)), nums[:i]) if i > 0 else 0
            rp = reduce(lambda x,y: (gcd(x, y)), nums[i+1:]) if i < len(nums) - 1 else 0
            if lp and rp:
                gd = gcd(lp, rp)
            else:
                gd = lp or rp
            
            llp = reduce(lambda x,y: (lcm(x, y)), nums[:i]) if i > 0 else 0
            rrp = reduce(lambda x,y: (lcm(x, y)), nums[i+1:]) if i < len(nums) - 1 else 0
            if llp and rrp:
                lm = lcm(llp, rrp)
            else:
                lm = llp or rrp
            ans = max(ans, gd * lm)
        return ans
            
                
                    
                    
            