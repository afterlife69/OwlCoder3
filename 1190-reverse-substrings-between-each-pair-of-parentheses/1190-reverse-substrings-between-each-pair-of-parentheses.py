class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = ['']
        for i in s:
            if i == '(':
                st.append('')
            elif i == ')':
                cur = st.pop()[::-1]
                st[-1] += cur
            else:
                st[-1] += i
        return st[-1]