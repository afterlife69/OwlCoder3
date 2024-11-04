class Solution:
    def compressedString(self, word: str) -> str:
        c = 1
        ans = ''
        for i in range(1, len(word)):
            if word[i] == word[i-1]:
                c += 1
            else:
                while c >= 9:
                    ans += '9' + word[i-1]
                    c -= 9
                if c > 0:
                    ans += str(c) + word[i-1]
                c = 1
        while c >= 9:
            ans += '9' + word[-1]
            c -= 9
        if c > 0:
            ans += str(c) + word[-1]
        return ans
                    