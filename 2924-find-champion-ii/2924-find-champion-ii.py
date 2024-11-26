class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        
        adj = [set() for i in range(n)]
        ind = [0] * n
        for u, v in edges:
            ind[v] += 1
            adj[u].add(v)
        
        q = deque()
        for i in range(n):
            if ind[i] == 0:
                q.append(i)
        if len(q) > 1:
            return -1
        return q[0]