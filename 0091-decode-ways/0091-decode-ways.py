class Solution:
    def numDecodings(self, s: str) -> int:
        l=[]
        ans=[]
        dp = [-1]*(len(s) + 1)
        def fun(ind,n,s):
            if ind==n:
                return 1
            if dp[ind] != -1:
                return dp[ind]
            ans = 0
            for i in range(ind,n):
                b=s[ind:i+1]
                a="".join(b)
                if len(a)<3 and a[0]!='0' and int(a)<27:
                    l.append(a)
                    ans += fun(i+1,n,s)
                    l.pop()
                if len(a)>2:
                    break
            dp[ind] = ans
            return ans
        n=len(s)
        return fun(0,n,s)