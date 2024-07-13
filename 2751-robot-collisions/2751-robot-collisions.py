class Solution:
    def survivedRobotsHealths(self, p: List[int], h: List[int], d: str) -> List[int]:
        v = list(zip(p,h,d))
        v.sort()
        cnt, mp = 0, defaultdict(int)
        for i in p:
            mp[i] = cnt
            cnt += 1
        st = []
        ans = []
        for pos,hel,drc in v:
            if drc == 'R':
                st.append([hel, pos])
            else:
                while st and st[-1][0] < hel:
                    st.pop()
                    hel -= 1
                if not st:
                    ans.append([hel, pos])
                elif st[-1][0] == hel:
                    st.pop()
                else:
                    st[-1][0] -= 1
        ans = ans + st
        ans.sort(key = lambda x : mp[x[1]])
        return [i[0] for i in ans]