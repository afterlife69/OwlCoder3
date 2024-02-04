class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        mp = Counter(t)
        need = len(mp)
        i,j,n = 0,0,len(s)
        ans,l,r = 1e9,-1,-1
        cur = defaultdict(lambda : 0)
        while j < n:
            if s[j] in mp:
                cur[s[j]]+=1
                if cur[s[j]] == mp[s[j]]:
                    need -= 1
            while i <= j and need == 0:
                if need == 0 and (j-i+1) < ans:
                    ans = j-i+1
                    l = i
                    r = j+1
                if s[i] in mp:
                    if cur[s[i]] == mp[s[i]]:
                        need+=1
                    cur[s[i]] -= 1
                i+=1
            j+=1
        return '' if l == -1 else s[l:r]