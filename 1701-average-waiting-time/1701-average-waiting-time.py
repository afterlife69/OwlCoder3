class Solution:
    def averageWaitingTime(self, cus: List[List[int]]) -> float:
        add = 0
        run = 0
        for a, t in cus:
            if a < run:
                add += abs(a - run) + t
                run += t
            else:
                add += t
                run = (a + t)
        return add / len(cus)
    