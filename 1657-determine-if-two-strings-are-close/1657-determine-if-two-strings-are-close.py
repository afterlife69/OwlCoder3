class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if(len(word1) != len(word2)):
            return 0
        a = Counter(word1)
        b = Counter(word2)
        return sorted(a.keys()) == sorted(b.keys()) and sorted(a.values()) == sorted(b.values())  