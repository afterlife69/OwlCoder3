class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        mp = Counter(arr)
        for i in arr:
            if mp[i] == 1:
                k -= 1
            if k == 0:
                return i
        return ''