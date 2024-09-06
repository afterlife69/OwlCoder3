# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        vis = set(nums)
        t = head
        ret, cur = None, None
        while t:
            if t.val not in vis:
                if not ret:
                    cur = t
                    ret = t
                else:
                    ret.next = t
                    ret = ret.next
            t = t.next
        ret.next = None
        return cur