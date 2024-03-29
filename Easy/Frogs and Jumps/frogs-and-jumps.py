#User function Template for python3

class Solution:
    def unvisitedLeaves(self, n, leaves, frogs):
    # code here
        l=[0]*(leaves+1)
        l[0]=1
        cnt=0
        for i in frogs:
            if i <= leaves and not l[i]:
                for j in range(i,leaves+1,i):
                    if l[j]==0:
                        l[j]+=1
                        cnt+=1
                    if cnt>=leaves:
                        break
                if cnt>=leaves:
                    break
        
        return leaves-cnt


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