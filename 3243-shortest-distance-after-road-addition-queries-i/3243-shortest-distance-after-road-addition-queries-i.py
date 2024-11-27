class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        
        ans = []
        jump = [[i+1] for i in range(n)]
        dist = [i for i in range(n)] 
        for u, v in queries:
            jump[u].append(v)
            dist[v] = min(dist[v], dist[u] + 1)
            q = deque([(0, 0)])
            vis = set([0])
            while q:
                node, lvl = q.popleft()
                if node == n - 1:
                    ans.append(lvl)
                    break
                for nei in jump[node]:
                    if nei not in vis:
                        q.append((nei, lvl + 1))
                        vis.add(nei)
        return ans