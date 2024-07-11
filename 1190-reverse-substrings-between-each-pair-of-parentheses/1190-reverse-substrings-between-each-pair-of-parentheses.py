class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = []
        v = [0] * len(s)
        for i in range(len(s)):
            if s[i] == '(':
                st.append(i)
            elif s[i] == ')':
                v[st[-1]] = i
                v[i] = st[-1]
                st.pop()
        i = 0
        add = 1
        ans = ''
        while i < len(s):
            if s[i] == '(' or s[i] == ')':
                i = v[i]
                add = -add
            else:
                ans += s[i]
            i += add
        return ans