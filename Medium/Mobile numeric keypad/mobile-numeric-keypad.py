#User function Template for python3
class Solution:
	def getCount(self, k):
		dp = {}
		def dfs(i,j,k):
		    if i < 0 or j < 0 or i > 3 or j > 2 or (i == 3 and (j == 0 or j == 2)):
		        return 0
		    if k == 0:
		        return 1
		    if (i,j,k) in dp:
		        return dp[(i,j,k)]
		    dp[(i,j,k)] = dfs(i,j,k-1) + dfs(i+1,j,k-1) + dfs(i-1,j,k-1) + dfs(i,j+1,k-1) + dfs(i,j-1,k-1)
		    return dp[(i,j,k)]
		ans = 0
		for i in range(4):
		    for j in range(3):
		        ans += dfs(i,j,k-1)
		return ans
		


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.getCount(n)
        print(ans)

# } Driver Code Ends