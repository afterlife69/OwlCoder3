#User function Template for python3

# arr    : list of integers denoting the elements of the array
# target : as specified in the problem statement
from collections import defaultdict
class Solution:
    def threeSumClosest (self, v, t):
        v.sort()
        ans = -1e9
        dis = 1e9
        mp = defaultdict(list)
        for i in range(len(v)):
            l, r = (i + 1), len(v) - 1
            while l < r:
                cur = v[l] + v[r] + v[i]
                if cur == t:
                    return t
                elif cur > t:
                    r -= 1
                else:
                    l += 1
                if abs(cur - t) <= dis:
                    dis = abs(cur - t)
                    mp[dis].append(cur)
        return max(mp[dis])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        k = int(input())
        ob = Solution()
        print(ob.threeSumClosest(A, k))

# } Driver Code Ends