class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        if x > y:
            st = []
            ans = 0
            for i in s:
                if i == 'b':
                    if st and st[-1] == 'a':
                        ans += x
                        st.pop()
                    else:
                        st.append(i)
                else:
                    st.append(i)
            st2 = []
            for i in st:
                if i == 'a':
                    if st2 and st2[-1] == 'b':
                        ans += y
                        st2.pop()
                    else:
                        st2.append(i)
                else:
                    st2.append(i)
            return ans
        else:
            st = []
            ans = 0
            for i in s:
                if i == 'a':
                    if st and st[-1] == 'b':
                        ans += y
                        st.pop()
                    else:
                        st.append(i)
                else:
                    st.append(i)
            st2 = []
            for i in st:
                if i == 'b':
                    if st2 and st2[-1] == 'a':
                        ans += x
                        st2.pop()
                    else:
                        st2.append(i)
                else:
                    st2.append(i)
            return ans