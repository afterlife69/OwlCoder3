class Solution:
    def maxLength(self, arr: List[str]) -> int:
        def dfs(i, cur):
            if i == len(arr):
                if len(set(cur)) == len(cur):
                    return len(cur)
                return 0
            l = dfs(i+1,cur + arr[i])
            r = dfs(i+1, cur)
            return max(l,r)
        return dfs(0,'')