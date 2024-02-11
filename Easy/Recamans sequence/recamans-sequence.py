#User function Template for python3

class Solution:
    def recamanSequence(self, n):
        vis = set([0])
        dp = [0]*(n)
        for i in range(1,n):
            if dp[i-1]-i > 0 and dp[i-1]-i not in vis:
                dp[i] = dp[i-1] - i
            else:
                dp[i] = dp[i-1] + i
            vis.add(dp[i])
        return dp


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.recamanSequence(n)
        for i in range(n):
            print(ans[i],end=" ")
        print()
# } Driver Code Ends