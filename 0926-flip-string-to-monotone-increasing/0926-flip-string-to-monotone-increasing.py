class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        @cache
        def dfs(i,f):
            if i == len(s):
                return 0
            ans = 1e9
            if s[i] == '1':
                if not f:
                    ans = min(ans,dfs(i+1,1),dfs(i+1,0)+1)
                else:
                    ans = dfs(i+1,f)
            else:
                if f:
                    ans = dfs(i+1,f)+1
                else:
                    ans = min(ans,dfs(i+1,0),dfs(i+1,1)+1)
            return ans
        return dfs(0,0)