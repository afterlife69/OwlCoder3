#User function Template for python3
class Solution:
    def isValid(self, str):
        try:
            x = str.split('.')
            if len(x) != 4:
                return 0
            if any(i.startswith('0') and len(i) > 1 for i in x):
                return 0
            for i in x:
                if int(i) > 255:
                    return 0
            return 1
        except:
            return 0



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends