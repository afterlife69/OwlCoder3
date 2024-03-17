class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        l,r = 0,len(intervals)-1
        while l <= r:
            m = (l+r) // 2
            if intervals[m][0] >= newInterval[0]:
                r = m - 1
            else:
                l = m + 1
        for i in range(len(intervals)):
            if newInterval[0] <= intervals[i][0] and newInterval[1] >= intervals[i][1]:
                intervals[i] = [-1,-1]
        intervals.insert(r+1,newInterval)
        ans = []
        for i in range(len(intervals)):
            if intervals[i] == [-1,-1]:
                continue
            if not ans or ans[-1][1] < intervals[i][0]:
                ans.append(intervals[i])
            else:
                ans[-1][1] = max(intervals[i][1],ans[-1][1])
        return ans