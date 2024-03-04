class Solution:
    def gcdSort(self, nums: List[int]) -> bool:
        
        par = [i for i in range(100001)]
        rank = [0]*len(par)
        def F(x):
            if par[x] == x:
                return x
            par[x] = F(par[x])
            return par[x]
        def U(u,v):
            u = F(u)
            v = F(v)
            if u == v:
                return
            if rank[u] > rank[v]:
                par[v] = u
                rank[u] += rank[v]
            else:
                par[u] = v
                rank[v] += rank[u]
                
        mp = defaultdict(int)
        for it in nums:
            for i in range(2,int(it ** .5)+1):
                if it % i == 0:
                    if mp[i]:
                        U(mp[i],it)
                    if mp[it//i]:
                        U(mp[it//i],it)
                    mp[i] = it
                    mp[it//i] = it
            if mp[it]:
                U(mp[it],it)
            mp[it] = it
        x = []
        for i in nums:
            heappush(x,i)
        for i in nums:
            cur = heappop(x)
            if F(i) != F(cur):
                return 0
        return 1