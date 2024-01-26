class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        c=[len(connections)]
        vis=[0]*n
        par=[i for i in range(n)]
        def findd(x):
            if x==par[x]:
                return x
            else:
                par[x]=findd(par[x])
                return par[x]
        def union(a,b):
            x=findd(a)
            y=findd(b)
            if x!=y:
                c[0]-=1
            par[y]=x
        for i in connections:
            union(i[0],i[1])
            vis[i[0]]=1
            vis[i[1]]=1
        d=set()
        for i in range(n):
            d.add(findd(i))
        d = len(d) - 1
        if d>c[0]:
            return -1
        
        return d