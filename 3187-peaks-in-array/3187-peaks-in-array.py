class Solution:
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        N = len(nums)
        fen = [0] * (N+1)
        def update(i):
            while i < N:
                fen[i] += 1
                i += (i & (-i))
                
        def removal(i):
            while i < N:
                fen[i] -= 1
                i += (i & (-i))
            
        def getSum(i):
            ans = 0
            while i > 0:
                ans += fen[i]
                i -= (i & (-i))
            return ans
        def valid(a):
            curAns =  a > 0 and a < len(nums)-1
            if curAns:
                curAns &= nums[a] > nums[a-1] and nums[a] > nums[a+1]
            return curAns
                
        
        for i in range(1,len(nums)-1):
            if nums[i] > nums[i-1] and nums[i] > nums[i+1]:
                update(i)
        ans = []
        for t,a,b in queries:
            if t == 1:
                if a == b:
                    ans.append(0)
                else:
                    ans.append(getSum(b-1) - getSum(a))
            else:
                vbC = valid(a)
                vbL = valid(a-1)
                vbR = valid(a+1)
                nums[a] = b
                vaC = valid(a)
                vaL = valid(a-1)
                vaR = valid(a+1)
                
                if vbC and not vaC:
                    removal(a)
                elif not vbC and vaC:
                    update(a)
                    
                if vbL and not vaL:
                    removal(a-1)
                elif not vbL and vaL:
                    update(a-1)
                    
                if vbR and not vaR:
                    removal(a+1)
                elif not vbR and vaR:
                    update(a+1)
        return ans
                
                
                    
                        