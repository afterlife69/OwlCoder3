class Solution:
    def shortestDistanceAfterQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        
        dp = [0] * n
        adj = [[] for i in range(n)]
        k = 1
        for i in range(n-1):
            dp[n - i - 2] = k
            k += 1
            adj[i+1].append(i)
        ans = []
        for u,v in queries:
            adj[v].append(u)
            dp[u] = min(dp[u], dp[v] + 1)
            q = deque([(u, dp[u])])
            vis = [0] * n
            while q:
                node, lvl = q.popleft()
                dp[node] = min(dp[node],lvl)
                vis[node] = 1
                for it in adj[node]:
                    if not vis[it]:
                        q.append((it,lvl+1))
            ans.append(dp[0])
        return ans
                