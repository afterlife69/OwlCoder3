class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        mp = {2 : 12, 3 : 123, 4 : 1234, 5 : 12345, 6 : 123456, 7 : 1234567, 8 : 12345678
             ,9 : 123456789}
        res = []
        i = low
        sz = int(log(i,10))+1
        mx = int(log(high,10))+1
        while sz<=mx:
            cur = mp[sz]
            for j in range(1,11 - sz):
                if cur >= low and cur <= high:
                    res.append(cur)
                cur += int('1'*sz)
            sz += 1
            if cur >= high:
                break
        return res
            