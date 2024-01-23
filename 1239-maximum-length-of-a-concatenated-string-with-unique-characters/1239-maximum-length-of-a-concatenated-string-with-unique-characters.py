class Solution:
    def maxLength(self, arr: List[str]) -> int:
        l=[]
        ans=[]
        def fun(arr,i,n):
            if i==n:
                a=l.copy()
                b="".join(a)
                if len(set(b))==len(b):
                    ans.append(b)
                return
            l.append(arr[i])
            fun(arr,i+1,n)
            l.pop()
            fun(arr,i+1,n)
        n=len(arr)
        fun(arr,0,n)
        print(ans)
        return len(max(ans,key=len))