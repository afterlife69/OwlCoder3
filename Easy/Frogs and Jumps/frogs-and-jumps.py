#User function Template for python3

class Solution:
    def unvisitedLeaves(self, N, leaves, frogs):
        if min(frogs) == 1:
            return 0
        ok = [0]*(leaves+1)
        ok[0] = 1
        for i in range(N):
            if frogs[i] <= leaves and not ok[frogs[i]]:
                for j in range(frogs[i],leaves+1,frogs[i]):
                    ok[j] = 1
        return ok.count(0)
                    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    
    T = int(input())
    while T > 0: 
        N, leaves = [int(i) for i in input().split()]
        frogs = [int(i) for i in input().split()]
        ob = Solution()
        print(ob.unvisitedLeaves(N, leaves, frogs))
        
        T -= 1
# } Driver Code Ends