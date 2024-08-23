class Solution:
    def fractionAddition(self, s: str) -> str:
        v = []
        for i in range(len(s)):
            if s[i] == '/':
                cur = ''
                j = i -1
                while j >= 0 and (s[j].isdigit()):
                    cur = s[j] + cur
                    j -= 1
                a = int(cur)
                if j >= 0:
                    if s[j] == '-':
                        a *= -1
                cur1 = ''
                j = i + 1
                while j < len(s) and (s[j].isdigit()):
                    cur1 = cur1 + s[j]
                    j += 1
                
                v.append((a, int(cur1)))
                
        ans = v[0][1]
        for i in range(1, len(v)):
            ans = lcm(ans, v[i][1])
        # print(v)
        num = 0
        for i in range(len(v)):
            num += (ans // v[i][1]) * v[i][0]
        if num == 0:
            ans = 1
        elif ans % num == 0:
            ans //= num
            num = 1
        elif num % ans == 0:
            num //= ans
            ans = 1
        if ans < 0:
            ans *= -1
            num *= -1
        cur = gcd(num, ans)
        ret = str(num // cur) + '/' + str(ans // cur)
        return ret